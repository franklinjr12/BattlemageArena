#pragma once

#include "CharacterAttribute.hpp"

#include <Object.hpp>

class CharacterItem : public Object {
public:

	CharacterItem() {
		attributes.arcane = 0;
		attributes.dexterity = 0;
		attributes.fitness = 0;
		attributes.luck = 0;
		attributes.will = 0;
	}
	CharacterAttributes attributes;
};