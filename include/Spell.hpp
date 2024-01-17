#pragma once

#include "SpellElement.hpp"
#include "SpellEffect.hpp"
#include "GroupsDef.hpp"

#include <DynamicBody.hpp>
#include <Animation.hpp>
#include <Timer.hpp>

class Spell : public DynamicBody {
public:

	Spell(float cooldown_ms = 1000);

	bool cast(Vecf position, Vecf dir);
	void process_events(std::vector<event_bytes_type> data);
	// should implement those
	virtual void _cast(Vecf position, Vecf dir) {};
	virtual void _process_events(std::vector<event_bytes_type> data) {};

	float cooldown_ms = 1;
	float damage = 0;
	bool on_cooldown = false;
	Vecf direction;
	SpellElement element = SpellElement::ENERGY;
	SpellEffect effect = SpellEffect::NONE;
	ObjectId owner;
	Animation* animation;
	Timer* timer;
};