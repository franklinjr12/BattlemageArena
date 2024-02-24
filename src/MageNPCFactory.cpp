#include "MageNPCFactory.hpp"

#include "Game.hpp"

MageNPC* MageNPCFactory::create() {
    Vecf m1_pos = { DEFAULT_SCREEN_WIDTH / 2 - 200, DEFAULT_SCREEN_HEIGHT / 2 };
    MageNPC* m1 = new MageNPC(m1_pos);
    return m1;
}
