#include "ShopScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"
#include "ArenaFightSceneFactory.hpp"

#include <AssetsManager.hpp>
#include <EventsManager.hpp>
#include <TextDisplay.hpp>
#include <Button.hpp>

ShopScene::ShopScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc) : Scene(camera, background, w, h) {
	name = SHOP_NAME;
	player = pc;
	Font* font = AssetsManager::get_instance()->get_default_font();
	const int SPACING = 80;
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");

	auto* shop_name_display = new TextDisplay(position, img, "SHOP SCREEN", font);
	shop_name_display->name = "shop_display";
	uis.push_front(shop_name_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");

	auto* levelup_shop_display = new TextDisplay(position, img, "LVLUP", font);
	levelup_shop_display->name = "levelup_display";
	uis.push_front(levelup_shop_display);
	auto* levelup_shop_button = new Button(Vecf{position[0] + 100, position[1] - 30 }, button_image);
	levelup_shop_button->name = "levelup_shop_button";
	uis.push_front(levelup_shop_button);
	position[1] += SPACING;


	auto* items_shop_display = new TextDisplay(position, img, "ITEMS", font);
	items_shop_display->name = "items_display";
	uis.push_front(items_shop_display);
	auto* items_shop_button = new Button(Vecf{ position[0] + 100, position[1] - 30 }, button_image);
	items_shop_button->name = "items_shop_button";
	uis.push_front(items_shop_button);
	position[1] += SPACING;

	auto* fight_arena_display = new TextDisplay(position, img, "ARENA DIFF", font);
	fight_arena_display->name = "arena_display";
	uis.push_front(fight_arena_display);
	auto* fight_arena_button = new Button(Vecf{ position[0] + 100, position[1] - 30 }, button_image);
	fight_arena_button->name = "arena_button";
	uis.push_front(fight_arena_button);
	position[1] += SPACING;
	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

void ShopScene::_process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		for (auto* b : uis) {
			if (btn_id == b->id) {
				if (b->name == "levelup_shop_button") {
					EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
					game->change_scene(LEVEL_UP_NAME);
					return;
				}
				else if (b->name == "items_shop_button") {
					EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
					game->change_scene(ITEM_NAME);
					return;
				}
				else if (b->name == "arena_button") {
					EventsManager::getInstance()->unsubscribe(EventType::ButtonClicked, this);
					game->change_scene(ARENA_DIFFICULTY_SCENE_NAME);
					return;
				}
			}
		}
	}
	}
}

void ShopScene::on_scene_entered() {
	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}
