// built with arcane v0.4.1.6

#include "Game.hpp"
#include "PlayerCharacter.hpp"
#include "BattlemageArenaConstants.hpp"
#include "ArenaFightScene.hpp"
#include "ArenaFightSceneFactory.hpp"
#include "ArenaResultsScene.hpp"

#include <ArcaneVersion.hpp>
#include <AssetsManager.hpp>
#include <iostream>

int main(void) {
	printf("Running with arcane %s\n", arcane_version_string().c_str());

	game = new Game();
	
	auto asset_man = AssetsManager::get_instance();

	ArenaFightScene* arena_scene = ArenaFightSceneFactory::create(ARENA_DIFFICULTY_EASY);

	PlayerCharacter* pc = new PlayerCharacter();
	game->player = pc;
	arena_scene->add_body(pc);
	game->events_manager->subscribe(EventType::KeyboardInput, pc);
	game->events_manager->subscribe(EventType::MouseInput, pc);
	game->events_manager->subscribe(EventType::SceneChanged, pc);

	Image* background_results = asset_man->get_image("gray_background.png");
	background_results->resize(game->width, game->height);
	Camera* camera = new Camera(0, 0, game->width, game->height);
	ArenaResultsScene* arena_results_scene = new ArenaResultsScene(camera, background_results, game->width, game->height);

	game->current_scene = arena_scene;
	//game->current_scene = arena_results_scene;
	game->scenes.push_back(arena_scene);
	game->scenes.push_back(arena_results_scene);

	game->run();

	delete game;

	return 0;
}