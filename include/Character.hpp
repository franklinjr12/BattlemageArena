#pragma once

#include "Spell.hpp"

#include <DynamicBody.hpp>

enum class CharacterState {
	IDLE
};

class Character : public DynamicBody {
public:
	
	Character();

	virtual void _update();
	virtual void cast_spell(int spell_num, Vecf direction);
	virtual void attack();
	
	float health = 100;
	Vecf set_position;
	float dash_cooldown_ms = 1000;
	float attack_cooldown_ms = 1000;
	float attack_damage = 0;
	CharacterState state = CharacterState::IDLE;
	const float DEFAULT_VELOCITY = 4;
	const float POSITION_STOP_THRESHOLD = 5;
	std::vector<Spell*> spells;
	std::vector<SpellEffect*> effects_applied;
};