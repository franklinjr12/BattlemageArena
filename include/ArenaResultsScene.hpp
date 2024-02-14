#pragma once

#include <Scene.hpp>

class ArenaResultsScene : public Scene {
public:
	
	ArenaResultsScene(Camera* camera, Image* background, uint32_t w, uint32_t h);
	void _update() override;
	void _draw() override;
};