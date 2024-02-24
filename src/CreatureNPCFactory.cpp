#include "CreatureNPCFactory.hpp"

#include "Game.hpp"

CreatureNPC* CreatureNPCFactory::create(Vecf position) {
	Vecf c_pos;
	if (position == nullptr)
		memcpy(c_pos, Vecf{ (float)DEFAULT_SCREEN_WIDTH / 2 + 200, (float)DEFAULT_SCREEN_HEIGHT / 2 }, sizeof(Vecf));
	else
		memcpy(c_pos, position, sizeof(Vecf));
	auto* c = new CreatureNPC(c_pos);
	return c;
}
