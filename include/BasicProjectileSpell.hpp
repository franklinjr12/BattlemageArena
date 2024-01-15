#pragma once

#include "Spell.hpp"

class BasicProjectileSpell : public Spell {
public:

	BasicProjectileSpell();

	virtual void _cast(Vecf position, Vecf dir);

	float damage = 1;
	float cooldown_ms = 500;
	float projectile_velocity = 2;
};