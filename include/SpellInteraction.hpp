#pragma once

#include "Spell.hpp"
#include "Character.hpp"

class SpellInteraction {
public:

	static void interact(Spell* s1, Spell* s2);
	static void interact(Spell* s, Character* c);
};