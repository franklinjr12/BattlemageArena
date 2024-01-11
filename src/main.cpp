// built with arcane v0.4.1.3

#include "Game.hpp"
#include "PlayerCharacter.hpp"

#include <ArcaneVersion.hpp>
#include <AssetsManager.hpp>
#include <iostream>

int main(void) {
	printf("Running with arcane %s\n", arcane_version_string().c_str());

	game = new Game();
	//game->init();
	
	auto asset_man = AssetsManager::get_instance();

	Camera* camera = new Camera(0, 0, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
	Image* background = asset_man->get_image("battle_arena.png");
	background->resize(game->width, game->height);
	Scene* scene = new Scene(camera, background, DEFAULT_SCREEN_WIDTH * 2, DEFAULT_SCREEN_HEIGHT * 2);
	scene->gravity = 0;

	PlayerCharacter* pc = new PlayerCharacter();
	game->player = pc;
	scene->add_body(pc);
	game->events_manager->subscribe(EventType::KeyboardInput, pc);
	game->events_manager->subscribe(EventType::MouseInput, pc);

	game->current_scene = scene;

	game->run();

	delete game;

	return 0;
}