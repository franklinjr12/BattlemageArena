#pragma once

#include "SpellElement.hpp"
#include "SpellEffect.hpp"
#include "GroupsDef.h"

#include <DynamicBody.hpp>
#include <Animation.hpp>

class Spell : public DynamicBody {
public:

	Spell(){
		name = "spell";
		groups.push_back((ObjectGroup)GameGroups::SPELL);
	}

	bool cast() {

	}

	float cooldown = 1;
	float damage = 0;
	SpellElement element;
	SpellEffect effect;
	ObjectId owner;
	Animation* animation;
};