#include "LevelUpScene.hpp"

#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <Button.hpp>
#include <EventsManager.hpp>
#include <TextDisplay.hpp>
#include <UiComponent.hpp>
#include <format>

TextDisplay* get_text_display_by_name(std::forward_list<UiComponent*> uis, std::string name) {
	for (auto* e : uis) {
		if (e->name == name) {
			return (TextDisplay*)e;
		}
	}
	return nullptr;
}

LevelUpScene::LevelUpScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc) : Scene(camera, background, w, h) {
	name = LEVEL_UP_NAME;
	//wont use add_body because don't want the player to do update and draw
	player = pc;

	const int SPACING = 80;
	Font* font = AssetsManager::get_instance()->get_default_font();
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");

	auto* points_display = new TextDisplay(position, img, std::format("{} points left", pc->attributes.points), font);
	points_display->name = "points_display";
	uis.push_front(points_display);
	position[1] += SPACING;

	auto* will_display = new TextDisplay(position, img, std::format("{} will", pc->attributes.will), font);
	will_display->name = "will_display";
	uis.push_front(will_display);
	position[1] += SPACING;

	auto* arcane_display = new TextDisplay(position, img, std::format("{} arcane", pc->attributes.arcane), font);
	arcane_display->name = "arcane_display";
	uis.push_front(arcane_display);
	position[1] += SPACING;

	auto* dexterity_display = new TextDisplay(position, img, std::format("{} dexterity", pc->attributes.dexterity), font);
	dexterity_display->name = "dexterity_display";
	uis.push_front(dexterity_display);
	position[1] += SPACING;

	auto* luck_display = new TextDisplay(position, img, std::format("{} luck", pc->attributes.luck), font);
	luck_display->name = "luck_display";
	uis.push_front(luck_display);
	position[1] += SPACING;

	auto* fitness_display = new TextDisplay(position, img, std::format("{} fitness", pc->attributes.fitness), font);
	fitness_display->name = "fitness_display";
	uis.push_front(fitness_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");
	auto* close_button = new Button(position, button_image);
	close_button->name = "close_button";
	uis.push_front(close_button);

	position[0] = 150;
	position[1] = game->height / 2;
	auto* shop_display = new TextDisplay(position, img, "LEVEL UP SHOP", font);
	shop_display->name = "level_up_shop_display";
	uis.push_front(shop_display);

	position[0] = game->width / 2 + 150;
	position[1] = SPACING * 2 - 30;

	auto* will_button = new Button(position, button_image);
	will_button->name = "will_button";
	uis.push_front(will_button);
	position[1] += SPACING;

	auto* arcane_button = new Button(position, button_image);
	arcane_button->name = "arcane_button";
	uis.push_front(arcane_button);
	position[1] += SPACING;

	auto* dexterity_button = new Button(position, button_image);
	dexterity_button->name = "dexterity_button";
	uis.push_front(dexterity_button);
	position[1] += SPACING;

	auto* luck_button = new Button(position, button_image);
	luck_button->name = "luck_button";
	uis.push_front(luck_button);
	position[1] += SPACING;

	auto* fitness_button = new Button(position, button_image);
	fitness_button->name = "fitness_button";
	uis.push_front(fitness_button);
	position[1] += SPACING;


	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
	EventsManager::getInstance()->subscribe(EventType::MouseInput, this);
	EventsManager::getInstance()->subscribe(EventType::SceneChanged, this);
}

LevelUpScene::~LevelUpScene() {
	EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
	EventsManager::getInstance()->unsubscribe(EventType::MouseInput, this);
	EventsManager::getInstance()->unsubscribe(EventType::SceneChanged, this);
	// should delete all memory allocated
}

void LevelUpScene::_update() {
	// might not need
}

void LevelUpScene::_process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		for (auto* b : uis) {
			if (btn_id == b->id) {
				if (b->name == "close_button") {
					game->change_scene(SHOP_NAME);
				}
				if (b->name == "will_button" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.will;
					get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
					get_text_display_by_name(uis, "will_display")->text = std::format("{} will", player->attributes.will);
				}
				if (b->name == "arcane_button" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.arcane;
					get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
					get_text_display_by_name(uis, "arcane_display")->text = std::format("{} arcane", player->attributes.arcane);
				}
				if (b->name == "dexterity_button" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.dexterity;
					get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
					get_text_display_by_name(uis, "dexterity_display")->text = std::format("{} dexterity", player->attributes.dexterity);
				}
				if (b->name == "luck_button" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.luck;
					get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
					get_text_display_by_name(uis, "luck_display")->text = std::format("{} luck", player->attributes.luck);
				}
				if (b->name == "fitness_button" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.fitness;
					get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
					get_text_display_by_name(uis, "fitness_display")->text = std::format("{} fitness", player->attributes.fitness);
				}

			}

		}
		break;
	}
	case (event_bytes_type)EventType::SceneChanged: {
		std::string scene_name = "";
		int size = (int)data[1];
		for (int i = 2; i < 2 + size; i++) {
			scene_name += (char)data[i];
		}
		if (scene_name == name) {
			// in case we entered the scene need to update the displays
			get_text_display_by_name(uis, "points_display")->text = std::format("{} points left", player->attributes.points);
			get_text_display_by_name(uis, "will_display")->text = std::format("{} will", player->attributes.will);
			get_text_display_by_name(uis, "arcane_display")->text = std::format("{} arcane", player->attributes.arcane);
			get_text_display_by_name(uis, "dexterity_display")->text = std::format("{} dexterity", player->attributes.dexterity);
			get_text_display_by_name(uis, "luck_display")->text = std::format("{} luck", player->attributes.luck);
			get_text_display_by_name(uis, "fitness_display")->text = std::format("{} fitness", player->attributes.fitness);
		}
		break;
	}
	}
}
