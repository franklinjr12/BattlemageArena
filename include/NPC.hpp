#pragma once

#include "Character.hpp"

class NPC : public Character {
public:

	NPC();
	void _update();

	float attack_distance;
	const float DEFAULT_ATTACK_DISTANCE = 200;
	float drop_experience = 0;
};