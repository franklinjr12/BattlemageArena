#pragma once

#include "SpellElement.hpp"
#include "SpellEffect.hpp"
#include "GroupsDef.hpp"

#include <Object.hpp>
#include <Animation.hpp>
#include <Timer.hpp>

class Spell : public Object {
public:

	Spell(float cooldown_ms = 1000);

	bool cast(Vecf position, Vecf dir, float extra_damage=1);
	void process_events(std::vector<event_bytes_type> data);
	void set_cooldown(float ms);
	float get_cooldown();
	// should implement those
	virtual void _cast(Vecf position, Vecf dir) {};
	virtual void _process_events(std::vector<event_bytes_type> data) {};

	bool on_cooldown = false;
	float damage = 0;
	float extra_damage = 0;
	float lifetime_ms = 2000;
	Vecf direction;
	SpellElement element = SpellElement::ENERGY;
	SpellEffect effect = SpellEffect::NONE;
	ObjectId owner;
	Image* image;
	Image* spell_ui;
	Animation* animation;
	Timer* timer;
protected:
	float cooldown_ms = 1;
};