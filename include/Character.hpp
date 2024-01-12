#pragma once

#include "Spell.hpp"

#include <DynamicBody.hpp>

class Character : public DynamicBody {
public:
	
	Character();

	virtual void _update();
	virtual void cast_spell(int spell_num, Vecf direction);

	const float DEFAULT_VELOCITY = 4;
	const float POSITION_STOP_THRESHOLD = 5;
	Vecf set_position;
	std::vector<Spell*> spells;
	float health_points;
};