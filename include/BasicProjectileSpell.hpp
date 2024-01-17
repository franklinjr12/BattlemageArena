#pragma once

#include "Spell.hpp"

class BasicProjectileSpell : public Spell {
public:

	BasicProjectileSpell();

	virtual void _cast(Vecf position, Vecf dir);

	float projectile_velocity = 2;
};