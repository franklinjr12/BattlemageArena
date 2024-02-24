#include "CreatureNPCFactory.hpp"

#include "Game.hpp"

CreatureNPC* CreatureNPCFactory::create() {
	Vecf c1_pos = { DEFAULT_SCREEN_WIDTH / 2 + 200, DEFAULT_SCREEN_HEIGHT / 2 };
	auto* c1 = new CreatureNPC(c1_pos);
	return c1;
}
