#pragma once

#include "Character.hpp"

class PlayerCharacter : public Character {
public:

	PlayerCharacter();

	void process_events(std::vector<event_bytes_type> data);
	void _draw() override;
	void _update();

	const float PLAYER_DEFAULT_VELOCITY = 4;
	Image* player_right;
	Image* player_left;
};