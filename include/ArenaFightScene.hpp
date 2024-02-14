#pragma once

#include <Scene.hpp>

class ArenaFightScene : public Scene {
public:

	ArenaFightScene(Camera* camera, Image* background, uint32_t w, uint32_t h);
	void _update() override;
	void _draw() override;
};