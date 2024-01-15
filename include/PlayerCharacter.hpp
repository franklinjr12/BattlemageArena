#pragma once


#include "Character.hpp"

class PlayerCharacter : public Character {
public:

	PlayerCharacter();

	void process_events(std::vector<event_bytes_type> data);
	void _update();
	//void cast_spell(int spell_num);

	const float PLAYER_DEFAULT_VELOCITY = 4;
	Image* player_right;
	Image* player_left;
};