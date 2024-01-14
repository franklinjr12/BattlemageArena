#pragma once

#include "Spell.hpp"

class BasicProjectileSpell : public Spell {
public:

	BasicProjectileSpell(Vecf pos, Vecf v);

	float damage = 1;
};