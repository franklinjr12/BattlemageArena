#pragma once

#include "NPC.hpp"

namespace creaturenpc {
	const float DEFAULT_CREATURE_DAMAGE = 5;
	const float DEFAULT_CREATURE_SPEED = 0.5;
	const float DEFAULT_CREATURE_HP = 20;
	const float DEFAULT_ATTACK_DISTANCE = 100;
}

using namespace creaturenpc;

class CreatureNPC : public NPC {
public:

	CreatureNPC(Vecf c_pos, Image* c_image = nullptr, float c_damage = DEFAULT_CREATURE_DAMAGE,
		float c_speed = DEFAULT_CREATURE_SPEED, float c_hp = DEFAULT_CREATURE_HP);

	virtual void attack(Vecf dir) override;
};