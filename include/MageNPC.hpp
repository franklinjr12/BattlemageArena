#pragma once

#include "NPC.hpp"

namespace magenpc {
	const float DEFAULT_MAGE_SPEED = 0.3;
	const float DEFAULT_MAGE_HP = 30;
	const float DEFAULT_ATTACK_DISTANCE = 300;
	const int DEFAULT_ARCANE = 5;
}

using namespace magenpc;

class MageNPC : public NPC {
public:

	MageNPC(Vecf m_pos, Image* m_image = nullptr,
		float c_speed = DEFAULT_MAGE_SPEED, float c_hp = DEFAULT_MAGE_HP);

	virtual void attack(Vecf dir) override;
};