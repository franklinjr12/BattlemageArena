#pragma once

#include <Scene.hpp>

#include <TextDisplay.hpp>
#include <Button.hpp>

class ArenaResultsScene : public Scene {
public:
	
	ArenaResultsScene(Camera* camera, Image* background, uint32_t w, uint32_t h);
	void _update() override;
	void _draw() override;
	void _process_events(std::vector<event_bytes_type> data);

	TextDisplay* time_display;
	TextDisplay* enemies_count_display;
	TextDisplay* difficulty_display;
	TextDisplay* gold_display;
	TextDisplay* experience_display;
	Button* close_results_button;
};