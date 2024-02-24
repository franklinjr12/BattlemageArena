#include "MageNPCFactory.hpp"

#include "Game.hpp"

MageNPC* MageNPCFactory::create(Vecf position) {
    Vecf m_pos;
    if (position == nullptr)
        memcpy(m_pos, Vecf{ (float)DEFAULT_SCREEN_WIDTH / 2 + 200, (float)DEFAULT_SCREEN_HEIGHT / 2 }, sizeof(Vecf));
    else
        memcpy(m_pos, position, sizeof(Vecf));
    auto* m = new MageNPC(m_pos);
    return m;
}
