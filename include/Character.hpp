#pragma once

#include "Spell.hpp"
#include "HealthBar.hpp"

#include <DynamicBody.hpp>

enum class CharacterState {
	IDLE,
	CHASING,
	ATTACKING
};

class CharacterAttributes {
public:
	int will = 1; //hp applied levelling up
	int arcane = 1; //damage applied on cast
	int dexterity = 1; //cooldowns applied levelling up
	int luck = 1; //critical hits not applied yet
	int fitess = 1; //speed applied on inherited characters
};

class CharacterDash : public Object {
public:

	CharacterDash();
	bool cast();
	void process_events(std::vector<event_bytes_type> data);
	bool on_cooldown = false;
	Timer* dash_timer = nullptr;
};

class Character : public DynamicBody {
public:
	
	Character();

	virtual void _draw() override;
	virtual void _update();
	virtual void cast_spell(int spell_num, Vecf direction);
	virtual void attack(Vecf dir);
	bool do_dash(Vecf dash_direction);
	
	float health = 100;
	HealthBar* health_bar = nullptr;
	Vecf set_position;
	float dash_cooldown_ms = 1000;
	CharacterDash dash;
	float attack_cooldown_ms = 1000;
	float attack_damage = 0;
	CharacterState state = CharacterState::IDLE;
	float speed_modifier = 1;
	const float DEFAULT_VELOCITY = 4;
	const float POSITION_STOP_THRESHOLD = 5;
	std::vector<Spell*> spells;
	std::vector<SpellEffect*> effects_applied;
	CharacterAttributes attributes;
};