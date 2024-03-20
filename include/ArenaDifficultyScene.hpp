#pragma once

#include <Scene.hpp>

class ArenaDifficultyScene : public Scene {
public:

	ArenaDifficultyScene(Camera* camera, Image* background, uint32_t w, uint32_t h);
	void _process_events(std::vector<event_bytes_type> data) override;
	void on_scene_entered() override;
	void _draw() override;

private:
	bool was_draw_once = false;
};