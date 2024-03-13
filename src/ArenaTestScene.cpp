#include "ArenaTestScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <Button.hpp>

ArenaTestScene::ArenaTestScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = "arena_test_scene";
	gravity = 0;

	const int SPACING = 80;
	Vecf position = { game->width / 2, SPACING };
	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");

	auto* add_exp_button = new Button(position, button_image);
	add_exp_button->name = "add_exp_button";
	uis.push_front(add_exp_button);
	position[1] += SPACING;

	auto* close_button = new Button(position, button_image);
	close_button->name = "close_button";
	uis.push_front(close_button);

	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

void ArenaTestScene::_process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::ButtonClicked: {
		ObjectId btn_id = (ObjectId)data[1];
		for (auto* b : uis) {
			if (btn_id == b->id) {
				if (b->name == "close_button") {
					game->change_scene(SHOP_NAME);
				}
				else if (b->name == "add_exp_button") {
					auto* p = game->player;
					auto current_level = p->player_exp->current_level;
					p->player_exp->add(50);
					auto new_level = p->player_exp->current_level;
					if (current_level < new_level) {
						p->attributes.points++;
					}
				}
			}
		}
	}
	}
}
