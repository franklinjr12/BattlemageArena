#include "LevelUpScene.hpp"

#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <Button.hpp>
#include <EventsManager.hpp>
#include <TextDisplay.hpp>
#include <format>

LevelUpScene::LevelUpScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc) : Scene(camera, background, w, h) {
	name = LEVEL_UP_NAME;
	//wont use add_body because don't want the player to do update and draw
	player = pc;
	// create the UI for the attributes and the buttons
	const int SPACING = 80;
	Font* font = AssetsManager::get_instance()->get_default_font();
	Vecf position = { game->width / 2, SPACING };
	Image* img = AssetsManager::get_instance()->get_image("transparent_10x10.png");

	auto* points_display = new TextDisplay(position, img, std::format("{} points left", pc->attributes.points), font);
	points_display->name = "points";
	uis.push_front(points_display);
	position[1] += SPACING;

	auto* button_image = AssetsManager::get_instance()->get_image("basic_button.png");
	auto* close_button = new Button(position, button_image);
	uis.push_front(close_button);


	EventsManager::getInstance()->subscribe(EventType::ButtonClicked, this);
}

void LevelUpScene::_update() {
	// might not need
}

void LevelUpScene::_process_events(std::vector<event_bytes_type> data) {
	// will hear to the buttons
}
