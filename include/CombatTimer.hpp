#pragma once

#include <TextDisplay.hpp>
#include <chrono>

class CombatTimer : public UiComponent{
public:

	CombatTimer(int time_s);
	void draw() override;
	void _update() override;
	TextDisplay* td;
	std::chrono::system_clock::time_point start_time;
	std::chrono::seconds combat_time;
	int elapsed_time = 0;
};