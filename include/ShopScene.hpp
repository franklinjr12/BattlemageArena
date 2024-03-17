#pragma once

#include "PlayerCharacter.hpp"

#include <Scene.hpp>

class ShopScene : public Scene {
public:

	ShopScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc);
	void _process_events(std::vector<event_bytes_type> data) override;
	void on_scene_entered() override;
	PlayerCharacter* player = nullptr;
};