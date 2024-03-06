#pragma once

#include "PlayerCharacter.hpp"

#include <Scene.hpp>

class LevelUpScene : public Scene {
public:

	LevelUpScene(Camera* camera, Image* background, uint32_t w, uint32_t h, PlayerCharacter* pc);
	~LevelUpScene();
	void _update() override;
	void _process_events(std::vector<event_bytes_type> data) override;
	PlayerCharacter* player = nullptr;
};