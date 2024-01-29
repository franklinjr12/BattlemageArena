// built with arcane v0.4.1.6

#include "Game.hpp"
#include "PlayerCharacter.hpp"
#include "CombatTimer.hpp"
#include "NPC.hpp"

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

	auto* cb = new CombatTimer(120);
	scene->uis.push_front(cb);

	NPC* c1 = new NPC();
	Vecf c1_pos = { DEFAULT_SCREEN_WIDTH / 2, DEFAULT_SCREEN_HEIGHT / 2 };
	c1->image = AssetsManager::get_instance()->get_image("big_demon_run_anim_f3.png");
	c1->rectangle = new BodyRectangle(c1_pos, c1->image->width, c1->image->height);
	c1->setX(c1_pos[0]);
	c1->setY(c1_pos[1]);
	c1->health_bar = new HealthBar();
	scene->add_body(c1);

	game->current_scene = scene;

	game->run();

	delete game;

	return 0;
}