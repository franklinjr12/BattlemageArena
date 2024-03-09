#include "ItemShopScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <Button.hpp>
#include <AssetsManager.hpp>
#include <EventsManager.hpp>

ItemShopScene::ItemShopScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc) : Scene(camera, background, w, h) {
	
	name = ITEM_NAME;
	player = pc;
	const int SPACING = 120;
	Vecf position = { game->width / 2, SPACING };

	auto* will_image = AssetsManager::get_instance()->get_image("will_item.png");
	auto* will_button = new Button(position, will_image);
	will_button->name = "will_button";
	uis.push_front(will_button);
	position[1] += SPACING;

	auto* arcane_image = AssetsManager::get_instance()->get_image("arcane_item.png");
	auto* arcane_button = new Button(position, arcane_image);
	arcane_button->name = "arcane_button";
	uis.push_front(arcane_button);
	position[1] += SPACING;

	auto* dexterity_image = AssetsManager::get_instance()->get_image("dexterity_item.png");
	auto* dexterity_button = new Button(position, dexterity_image);
	dexterity_button->name = "dexterity_button";
	uis.push_front(dexterity_button);
	position[1] += SPACING;

	auto* luck_image = AssetsManager::get_instance()->get_image("luck_item.png");
	auto* luck_button = new Button(position, luck_image);
	luck_button->name = "luck_button";
	uis.push_front(luck_button);
	position[1] += SPACING;

	auto* fitness_image = AssetsManager::get_instance()->get_image("fitness_item.png");
	auto* fitness_button = new Button(position, fitness_image);
	fitness_button->name = "fitness_button";
	uis.push_front(fitness_button);
	position[1] += SPACING;

	position[0] = 100;
	position[1] = game->height/2;

	Font* font = AssetsManager::get_instance()->get_default_font();
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");
	gold_display = new TextDisplay(position, img, std::format("{} gold", pc->gold), font);
	gold_display->name = "gold_display";
	uis.push_front(gold_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");
	auto* close_button = new Button(position, button_image);
	close_button->name = "close_button";
	uis.push_front(close_button);


	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
	EventsManager::getInstance()->subscribe(EventType::MouseInput, this);
}

void ItemShopScene::_process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		for (auto* b : uis) {
			if (btn_id == b->id) {
				if (b->name == "close_button") {
					game->change_scene(SHOP_NAME);
				}
				if (player->gold > 0 && b->name == "will_button") {
					--player->gold;
					auto* item = new CharacterItem();
					++item->attributes.will;
					player->items.push_back(item);
					gold_display->text = std::format("{} gold", player->gold);
				}
				if (player->gold > 0 && b->name == "arcane_button") {
					--player->gold;
					auto* item = new CharacterItem();
					++item->attributes.arcane;
					player->items.push_back(item);
					gold_display->text = std::format("{} gold", player->gold);
				}
				if (player->gold > 0 && b->name == "dexterity_button") {
					--player->gold;
					auto* item = new CharacterItem();
					++item->attributes.dexterity;
					player->items.push_back(item);
					gold_display->text = std::format("{} gold", player->gold);
				}
				if (player->gold > 0 && b->name == "luck_button") {
					--player->gold;
					auto* item = new CharacterItem();
					++item->attributes.luck;
					player->items.push_back(item);
					gold_display->text = std::format("{} gold", player->gold);
				}
				if (player->gold > 0 && b->name == "fitness_button") {
					--player->gold;
					auto* item = new CharacterItem();
					++item->attributes.fitness;
					player->items.push_back(item);
					gold_display->text = std::format("{} gold", player->gold);
				}
			}
		}
	}
	}
}