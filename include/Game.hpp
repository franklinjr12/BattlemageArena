#pragma once

#include <Application.hpp>

class Game : public Application {
public:

	Game();

	void game_loop() override;

	void game_draw() override;

	Font* font;
	Player* player;
};

extern Game* game;