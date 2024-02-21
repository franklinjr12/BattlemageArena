#include "ArenaResultsScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

ArenaResultsScene::ArenaResultsScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = ARENA_RESULTS_NAME;
	const int SPACING = 80;
	Font* font = AssetsManager::get_instance()->get_default_font();
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");
	//Image* img = AssetsManager::get_instance()->get_image("results_ui.png");
	time_display = new TextDisplay(position, img, "000s", font);
	uis.push_front(time_display);
	position[1] += SPACING;
	enemies_count_display = new TextDisplay(position, img, "000 killed", font);
	uis.push_front(enemies_count_display);
	position[1] += SPACING;
	difficulty_display = new TextDisplay(position, img, "normal difficulty", font);
	uis.push_front(difficulty_display);
	position[1] += SPACING;
	gold_display = new TextDisplay(position, img, "000 gold", font);
	uis.push_front(gold_display);
	position[1] += SPACING;
	experience_display = new TextDisplay(position, img, "000 exp", font);
	uis.push_front(experience_display);
}

void ArenaResultsScene::_update()
{
}

void ArenaResultsScene::_draw()
{
}
