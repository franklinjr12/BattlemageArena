#include "LevelUpScene.hpp"

#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <Button.hpp>
#include <EventsManager.hpp>
#include <TextDisplay.hpp>
#include <UiComponent.hpp>
#include <format>

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
	will_display->name = "will";
	uis.push_front(will_display);
	position[1] += SPACING;

	auto* arcane_display = new TextDisplay(position, img, std::format("{} arcane", pc->attributes.arcane), font);
	arcane_display->name = "arcane";
	uis.push_front(arcane_display);
	position[1] += SPACING;

	auto* dexterity_display = new TextDisplay(position, img, std::format("{} dexterity", pc->attributes.dexterity), font);
	dexterity_display->name = "dexterity";
	uis.push_front(dexterity_display);
	position[1] += SPACING;

	auto* luck_display = new TextDisplay(position, img, std::format("{} luck", pc->attributes.luck), font);
	luck_display->name = "luck";
	uis.push_front(luck_display);
	position[1] += SPACING;

	auto* fitness_display = new TextDisplay(position, img, std::format("{} fitness", pc->attributes.fitness), font);
	fitness_display->name = "fitness";
	uis.push_front(fitness_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");
	auto* close_button = new Button(position, button_image);
	close_button->name = "close";
	uis.push_front(close_button);

	position[0] = game->width / 2 + 150;
	position[1] = SPACING * 2 - 30;

	auto* will_button = new Button(position, button_image);
	will_button->name = "will";
	uis.push_front(will_button);
	position[1] += SPACING;

	auto* arcane_button = new Button(position, button_image);
	arcane_button->name = "arcane";
	uis.push_front(arcane_button);
	position[1] += SPACING;

	auto* dexterity_button = new Button(position, button_image);
	dexterity_button->name = "dexterity";
	uis.push_front(dexterity_button);
	position[1] += SPACING;

	auto* luck_button = new Button(position, button_image);
	luck_button->name = "luck";
	uis.push_front(luck_button);
	position[1] += SPACING;

	auto* fitness_button = new Button(position, button_image);
	fitness_button->name = "fitness";
	uis.push_front(fitness_button);
	position[1] += SPACING;


	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

LevelUpScene::~LevelUpScene() {
	EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
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
				if (b->name == "close") {
					// go back to shop screen
				}
				if (b->name == "will" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.will;
					std::forward_list<UiComponent*>& my_uis = uis;
					TextDisplay* points_display = (TextDisplay*)GetObjectFromCollectionByName(my_uis, "points_display");
					points_display->text = std::format("{} points left", player->attributes.points);
					TextDisplay* will_display = (TextDisplay*)GetObjectFromCollectionByName(uis, "will_display");
					will_display->text = std::format("{} will", player->attributes.will);
				}
				if (b->name == "arcane" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.arcane;
				}
				if (b->name == "dexterity" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.dexterity;
				}
				if (b->name == "luck" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.luck;
				}
				if (b->name == "fitness" && player->attributes.points > 0) {
					--player->attributes.points;
					++player->attributes.fitness;
				}

			}

		}
	}
	}
}
