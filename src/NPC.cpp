#include "NPC.hpp"

#include "Game.hpp"

NPC::NPC() {
	state = CharacterState::CHASING;
	groups.push_back((ObjectGroup)GameGroups::NPC);
	attack_distance = DEFAULT_ATTACK_DISTANCE;
}

void NPC::_update() {
	if (health_bar->get_hp() <= 0) {
		A2D_LOGI("NPC id {} {} died", id, name);
		groups.push_back((ObjectGroup)GameGroups::MARKDELETE);
	}
	switch (state) {
	case CharacterState::IDLE:
		break;
	case CharacterState::CHASING:{
		Vecf player_pos;
		player_pos[0] = game->player->getX();
		player_pos[1] = game->player->getY();
		if (DistanceVecf(Vecf{ getX(),getY() }, player_pos) <= attack_distance) {
			vel[0] = 0;
			vel[1] = 0;
			state = CharacterState::ATTACKING;
			A2D_LOGI("NPC {} attacking", id);
			break;
		}
		Vecf dir;
		dir[0] = player_pos[0] - getX();
		dir[1] = player_pos[1] - getY();
		float dir_mag = MagVecf(dir);
		dir[0] = dir[0] / dir_mag;
		dir[1] = dir[1] / dir_mag;
		vel[0] = dir[0] * DEFAULT_VELOCITY * speed_modifier * attributes.fitess;
		vel[1] = dir[1] * DEFAULT_VELOCITY * speed_modifier * attributes.fitess;
		break;
	}
	case CharacterState::ATTACKING: {
		Vecf player_pos;
		player_pos[0] = game->player->getX();
		player_pos[1] = game->player->getY();
		if (DistanceVecf(Vecf{ getX(),getY() }, player_pos) > attack_distance) {
			state = CharacterState::CHASING;
			A2D_LOGI("NPC {} chasing", id);
			break;
		}
		Vecf dir;
		dir[0] = player_pos[0] - getX();
		dir[1] = player_pos[1] - getY();
		float dir_mag = MagVecf(dir);
		dir[0] = dir[0] / dir_mag;
		dir[1] = dir[1] / dir_mag;
		attack(dir);
		break;
	}
	
	}
}
