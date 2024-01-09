#include "PlayerCharacter.hpp"
#include "Game.hpp"
#include "Projectile.hpp"

#include <AssetsManager.hpp>
#include <ArcaneUtils.hpp>

PlayerCharacter::PlayerCharacter() {
	player_left = new Image(*AssetsManager::get_instance()->get_image("fire_mage.png"));
	int w = 30;
	int h = 60;
	Vecf pos = { 500,500 };
	player_left->resize(w, h);
	player_right = new Image(*player_left);
	player_right->fliph();
	image = player_left;
	rectangle = new BodyRectangle(pos, w, h);
	setX(pos[0]);
	setY(pos[1]);
}

void PlayerCharacter::process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::MouseInput:
		// move command
		if (data[1] == GLFW_PRESS && data[2] == GLFW_MOUSE_BUTTON_RIGHT) {
			Vecf mouse_pos;
			mouse_pos[0] = data[3];
			mouse_pos[1] = data[4];
			set_position[0] = mouse_pos[0];
			set_position[1] = mouse_pos[1];
			Vecf dir;
			dir[0] = mouse_pos[0] - getX();
			dir[1] = mouse_pos[1] - getY();
			float dir_mag = MagVecf(dir);
			dir[0] = dir[0] / dir_mag;
			dir[1] = dir[1] / dir_mag;
			vel[0] = dir[0] * PLAYER_DEFAULT_VELOCITY;
			vel[1] = dir[1] * PLAYER_DEFAULT_VELOCITY;
		}
		break;
	case (event_bytes_type)EventType::KeyboardInput:
		//if (data[1] == GLFW_PRESS || data[1] == GLFW_REPEAT) {
		//	switch (data[2]) {
		//	case GLFW_KEY_UP:
		//		vel[1] = -PLAYER_DEFAULT_VELOCITY;
		//		break;
		//	case GLFW_KEY_DOWN:
		//		vel[1] = PLAYER_DEFAULT_VELOCITY;
		//		break;
		//	case GLFW_KEY_LEFT:
		//		vel[0] = -PLAYER_DEFAULT_VELOCITY;
		//		break;
		//	case GLFW_KEY_RIGHT:
		//		vel[0] = PLAYER_DEFAULT_VELOCITY;
		//		break;
		//	default:
		//		break;
		//	}
		//}
		if (data[1] == GLFW_RELEASE) {
			switch (data[2]) {
			case GLFW_KEY_Q:
				cast_spell(1);
				break;
			//case GLFW_KEY_UP:
			//case GLFW_KEY_DOWN:
			//	vel[1] = 0;
			//	break;
			//case GLFW_KEY_LEFT:
			//case GLFW_KEY_RIGHT:
			//	vel[0] = 0;
			//	break;
			default:
				break;
			}
		}
	}
}

void PlayerCharacter::_update() {
	if (DistanceVecf(set_position, Vecf{ getX(), getY() }) < POSITION_STOP_THRESHOLD) {
		vel[0] = 0;
		vel[1] = 0;
	}
	if (game->mouse_pos[0] > getX())
		image = player_right;
	else
		image = player_left;
}

void PlayerCharacter::cast_spell(int spell_num) {
	Vecf dir;
	dir[0] = (float)game->mouse_pos[0] - getX();
	dir[1] = (float)game->mouse_pos[1] - getY();
	float dir_mag = MagVecf(dir);
	dir[0] = dir[0] / dir_mag;
	dir[1] = dir[1] / dir_mag;
	Vecf p_initial_pos;
	p_initial_pos[0] = getX() + dir[0] * 10;
	p_initial_pos[1] = getY() + dir[1] * 10;
	Vecf p_vel;
	p_vel[0] = dir[0] * 10;
	p_vel[1] = dir[1] * 10;
	game->current_scene->add_body(new Projectile(p_initial_pos, p_vel));
}