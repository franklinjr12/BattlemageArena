#pragma once

#include "MageNPC.hpp"

class MageNPCFactory {
public:

	static MageNPC* create(Vecf position = nullptr);
};

