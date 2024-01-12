#pragma once

#include <DynamicBody.hpp>

class Spell : public DynamicBody {
public:

	Spell(){}

	float cooldown = 1;
	float damage = 0;
};