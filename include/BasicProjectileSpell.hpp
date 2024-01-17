#pragma once

#include "Spell.hpp"

class BasicProjectileSpell : public Spell {
public:

	BasicProjectileSpell(ObjectId owner);

	virtual void _cast(Vecf position, Vecf dir);

	float projectile_velocity = 2;
	const float DEFAULT_TIMEOUT = 500;
	ObjectId owner;
}; 