#pragma once

#include "SpellElement.hpp"
#include "SpellEffect.hpp"
#include "GroupsDef.h"

#include <DynamicBody.hpp>
#include <Animation.hpp>
#include <Timer.hpp>

class Spell : public DynamicBody {
public:

	Spell(float cooldown_ms = 1000);

	bool cast();
	void process_events(std::vector<event_bytes_type> data);
	virtual void _process_events(std::vector<event_bytes_type> data);

	float cooldown_ms = 1;
	float damage = 0;
	bool on_cooldown = false;
	SpellElement element;
	SpellEffect effect;
	ObjectId owner;
	Animation* animation;
	Timer* timer;
};