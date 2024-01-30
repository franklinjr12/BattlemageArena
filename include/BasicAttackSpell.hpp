#pragma once

#include "Spell.hpp"

class BasicAttackSpell : public Spell {
public:

	BasicAttackSpell(ObjectId owner);

	virtual void _cast(Vecf position, Vecf dir);

	float projectile_velocity = 0;
	const float DEFAULT_TIMEOUT = 500;
	const float DEFAULT_DAMAGE = 10;
	ObjectId owner;
};