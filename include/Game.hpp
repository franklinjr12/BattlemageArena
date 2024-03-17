#pragma once

#include "PlayerCharacter.hpp"
#include "ArenaResultsStats.hpp"

#include <Application.hpp>

class Game : public Application {
public:

	Game();

	void game_loop() override;

	void game_draw() override;

	void clear_arena_fight_scene();

	Font* font;
	PlayerCharacter* player;
	Image const* player_img;
	Scene* arena_fight_scene;
	Scene* arena_results_scene;
	ArenaResultsStats arena_results_stats;
};

extern Game* game;