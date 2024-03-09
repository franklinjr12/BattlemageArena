#pragma once

#include "PlayerCharacter.hpp"

#include <Scene.hpp>
#include <TextDisplay.hpp>

class ItemShopScene : public Scene {
public:

	ItemShopScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc);
	void _process_events(std::vector<event_bytes_type> data) override;

	PlayerCharacter* player;
	TextDisplay* gold_display;
};