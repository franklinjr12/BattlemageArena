// built with arcane v0.4.1.6

#include "Game.hpp"
#include "PlayerCharacter.hpp"
#include "BattlemageArenaConstants.hpp"
#include "ArenaFightSceneFactory.hpp"
#include "ArenaResultsScene.hpp"
#include "ArenaTestScene.hpp"
#include "LevelUpScene.hpp"
#include "ItemShopScene.hpp"
#include "ShopScene.hpp"

#include <ArcaneVersion.hpp>
#include <AssetsManager.hpp>
#include <iostream>

int main(void) {
	printf("Running with arcane %s\n", arcane_version_string().c_str());

	game = new Game();
	
	PlayerCharacter* pc = new PlayerCharacter();
	game->player = pc;
	pc->gold = 5;
	game->events_manager->subscribe(EventType::KeyboardInput, pc);
	game->events_manager->subscribe(EventType::MouseInput, pc);
	game->events_manager->subscribe(EventType::SceneChanged, pc);

	auto asset_man = AssetsManager::get_instance();

	ArenaFightScene* arena_scene = ArenaFightSceneFactory::create(ARENA_DIFFICULTY_EASY);
	arena_scene->add_body(pc);

	Image* background_results = asset_man->get_image("gray_background.png");
	background_results->resize(game->width, game->height);
	Camera* camera = new Camera(0, 0, game->width, game->height);
	ArenaResultsScene* arena_results_scene = new ArenaResultsScene(camera, background_results, game->width, game->height);

	Image* background_test = asset_man->get_image("battle_arena.png");
	background_test->resize(game->width, game->height);
	Camera* camera2 = new Camera(0, 0, game->width, game->height);
	auto* arena_test_scene = new ArenaTestScene(camera, background_test, game->width, game->height);
	arena_test_scene->add_body(pc);

	Image* background_shop = asset_man->get_image("gray_background.png");
	background_shop->resize(game->width, game->height);
	Camera* camera_shop = new Camera(0, 0, game->width, game->height);
	auto* shop_scene = new ShopScene(camera_shop, background_shop, game->width, game->height, pc);

	Image* background_levelup = asset_man->get_image("gray_background.png");
	background_levelup->resize(game->width, game->height);
	Camera* camera_levelup = new Camera(0, 0, game->width, game->height);
	auto* levelup_scene = new LevelUpScene(camera_levelup, background_levelup, game->width, game->height, pc);

	Image* background_items_shop = asset_man->get_image("item_shop.png");
	background_items_shop->resize(game->width, game->height);
	Camera* camera_items_shop = new Camera(0, 0, game->width, game->height);
	auto* items_shop_scene = new ItemShopScene(camera_items_shop, background_items_shop, game->width, game->height, pc);

	//game->current_scene = arena_scene;
	//game->current_scene = arena_results_scene;
	game->current_scene = arena_test_scene;
	//game->current_scene = levelup_scene;
	//game->current_scene = items_shop_scene;
	//game->current_scene = shop_scene;

	//game->scenes.push_back(arena_scene);
	game->scenes.push_back(arena_results_scene);
	game->scenes.push_back(arena_test_scene);
	game->scenes.push_back(shop_scene);
	game->scenes.push_back(levelup_scene);
	game->scenes.push_back(items_shop_scene);	

	game->run();

	delete game;

	return 0;
}