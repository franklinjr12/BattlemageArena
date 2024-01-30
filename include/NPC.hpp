#pragma once

#include "Character.hpp"

class NPC : public Character {
public:

	NPC();
	void _update();

	const float DEFAULT_ATTACK_DISTANCE = 50;
};