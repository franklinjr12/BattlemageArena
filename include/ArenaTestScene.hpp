#pragma once

#include <Scene.hpp>

class ArenaTestScene : public Scene {
public:

	ArenaTestScene(Camera* camera, Image* background, uint32_t w, uint32_t h);
	void _process_events(std::vector<event_bytes_type> data) override;
};

