#pragma once

#include "PlayerCharacter.hpp"

#include <Application.hpp>

class Game : public Application {
public:

	Game();

	void game_loop() override;

	void game_draw() override;

	Font* font;
	PlayerCharacter* player;
	int npc_total_kills = 0;
	float experience_gained = 0;
};

extern Game* game;