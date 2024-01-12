#pragma once

#include "Spell.hpp"

class BasicSpell : public Spell {
public:

	BasicSpell(Vecf pos, Vecf v);

	float damage = 1;
};