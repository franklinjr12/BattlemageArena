#pragma once

#include <Application.hpp>

class Game : public Application {
public:

	void game_loop() override {
	}

	void game_draw() override {
	}
};

static Game* game;