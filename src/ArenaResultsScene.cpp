#include "ArenaResultsScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <format>

ArenaResultsScene::ArenaResultsScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = ARENA_RESULTS_NAME;
	const int SPACING = 80;
	Font* font = AssetsManager::get_instance()->get_default_font();
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");
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
	position[1] += SPACING;
	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");
	//close_results_button = new Button(position, button_image, button_image->width, button_image->height);
	close_results_button = new Button(position, button_image);
	uis.push_front(close_results_button);
	EventsManager::getInstance()->subscribe(EventType::SceneChanged, this);
	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

void ArenaResultsScene::_update()
{
}

void ArenaResultsScene::_draw()
{
}

void ArenaResultsScene::_process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::SceneChanged: {
		std::string scene_name = "";
		int size = (int)data[1];
		for (int i = 2; i < 2 + size; i++) {
			scene_name += (char)data[i];
		}
		if (scene_name == name) {
			// entered this scene
			// load the data from results
			auto& res = game->arena_results_stats;
			time_display->text = std::format("{}s", res.cleared_time);
			enemies_count_display->text = std::format("{} killed", res.enemies_killed);
			difficulty_display->text = std::format("{} difficulty", res.difficulty);
			gold_display->text = std::format("{} gold", res.gold_earned);
			experience_display->text = std::format("{} exp", res.experience_earned);
		}
		break;
	}
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		if (btn_id == close_results_button->id) {
			game->change_scene(SHOP_NAME);
		}
		break;
	}
	}
}
