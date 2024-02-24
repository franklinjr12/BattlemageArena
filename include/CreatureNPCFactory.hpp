#pragma once

#include "CreatureNPC.hpp"

class CreatureNPCFactory {
public:

	static CreatureNPC* create(Vecf position = nullptr);
};

