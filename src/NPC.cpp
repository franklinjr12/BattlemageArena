#include "NPC.hpp"

#include "Game.hpp"

NPC::NPC() {
	state = CharacterState::CHASING;
}

void NPC::_update() {
	if (state == CharacterState::CHASING) {
		Vecf player_pos;
		player_pos[0] = game->player->getX();
		player_pos[1] = game->player->getY();
		Vecf dir;
		dir[0] = player_pos[0] - getX();
		dir[1] = player_pos[1] - getY();
		float dir_mag = MagVecf(dir);
		dir[0] = dir[0] / dir_mag;
		dir[1] = dir[1] / dir_mag;
		vel[0] = dir[0] * DEFAULT_VELOCITY * 0.5;
		vel[1] = dir[1] * DEFAULT_VELOCITY * 0.5;
	}
}
