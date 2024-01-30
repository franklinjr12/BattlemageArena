#include "NPC.hpp"

#include "Game.hpp"

NPC::NPC() {
	state = CharacterState::CHASING;
	groups.push_back((ObjectGroup)GameGroups::NPC);
}

void NPC::_update() {
	switch (state) {
	case CharacterState::IDLE:
		break;
	case CharacterState::CHASING:{
		Vecf player_pos;
		player_pos[0] = game->player->getX();
		player_pos[1] = game->player->getY();
		if (DistanceVecf(Vecf{ getX(),getY() }, player_pos) <= DEFAULT_ATTACK_DISTANCE) {
			state = CharacterState::ATTACKING;
			break;
		}
		Vecf dir;
		dir[0] = player_pos[0] - getX();
		dir[1] = player_pos[1] - getY();
		float dir_mag = MagVecf(dir);
		dir[0] = dir[0] / dir_mag;
		dir[1] = dir[1] / dir_mag;
		vel[0] = dir[0] * DEFAULT_VELOCITY * speed_modifier;
		vel[1] = dir[1] * DEFAULT_VELOCITY * speed_modifier;
		break;
	}
	case CharacterState::ATTACKING: {
		Vecf player_pos;
		player_pos[0] = game->player->getX();
		player_pos[1] = game->player->getY();
		if (DistanceVecf(Vecf{ getX(),getY() }, player_pos) > DEFAULT_ATTACK_DISTANCE) {
			state = CharacterState::CHASING;
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
