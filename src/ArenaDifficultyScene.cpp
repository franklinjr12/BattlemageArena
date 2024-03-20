#include "ArenaDifficultyScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"
#include "ArenaFightSceneFactory.hpp"

#include <AssetsManager.hpp>
#include <EventsManager.hpp>
#include <TextDisplay.hpp>
#include <Button.hpp>

ArenaDifficultyScene::ArenaDifficultyScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = ARENA_DIFFICULTY_SCENE_NAME;
	Font* font = AssetsManager::get_instance()->get_default_font();
	const int SPACING = 80;
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");

	auto* difficulty_display = new TextDisplay(position, img, "DIFFICULTY SCREEN", font);
	difficulty_display->name = "difficulty_display";
	uis.push_front(difficulty_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");

	auto* easy_display = new TextDisplay(position, img, "EASY", font);
	easy_display->name = "easy_display";
	uis.push_front(easy_display);
	auto* easy_button = new Button(Vecf{ position[0] + 100, position[1] - 30 }, button_image);
	easy_button->name = "easy_button";
	uis.push_front(easy_button);
	position[1] += SPACING;

	auto* normal_display = new TextDisplay(position, img, "NORMAL", font);
	normal_display->name = "normal_display";
	uis.push_front(normal_display);
	auto* normal_button = new Button(Vecf{ position[0] + 100, position[1] - 30 }, button_image);
	normal_button->name = "normal_button";
	uis.push_front(normal_button);
	position[1] += SPACING;

	auto* hard_display = new TextDisplay(position, img, "HARD", font);
	hard_display->name = "hard_display";
	uis.push_front(hard_display);
	auto* hard_button = new Button(Vecf{ position[0] + 100, position[1] - 30 }, button_image);
	hard_button->name = "hard_button";
	uis.push_front(hard_button);
	position[1] += SPACING;
}

void ArenaDifficultyScene::_process_events(std::vector<event_bytes_type> data) {
	if (!was_draw_once) return;
	switch (data[0]) {
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		for (auto* b : uis) {
			if (btn_id == b->id) {
				std::string choosen_difficulty = "";
				if (b->name == "easy_button") {
					choosen_difficulty = ARENA_DIFFICULTY_EASY;
				}
				else if (b->name == "normal_button") {
					choosen_difficulty = ARENA_DIFFICULTY_NORMAL;
				}
				else if (b->name == "hard_button") {
					choosen_difficulty = ARENA_DIFFICULTY_HARD;
				}
				if (choosen_difficulty != "") {
					game->clear_arena_fight_scene();
					auto* arena = ArenaFightSceneFactory::create(choosen_difficulty);
					game->scenes.push_back(arena);
					EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
					game->change_scene(ARENA_FIGHT_NAME);
					was_draw_once = false;
					return;
				}
			}
		}
	}
	}
}

void ArenaDifficultyScene::on_scene_entered() {
	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

void ArenaDifficultyScene::_draw() {
	was_draw_once = true;
}
