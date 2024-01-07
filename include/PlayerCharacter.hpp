#pragma once


#include <Player.hpp>

class PlayerCharacter : public Player {
public:

	PlayerCharacter();

	void process_events(std::vector<event_bytes_type> data);
	void _update();
	void cast_spell(int spell_num);

	const float PLAYER_DEFAULT_VELOCITY = 4;
	const float POSITION_STOP_THRESHOLD = 5;
	Vecf set_position;
};