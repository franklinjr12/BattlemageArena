#pragma once

#include <TextDisplay.hpp>
#include <chrono>

class CombatTimer : public UiComponent{
public:

	CombatTimer(int time_s);
	void draw() override;
	TextDisplay* td;
	std::chrono::system_clock::time_point start_time;
	std::chrono::seconds combat_time;
};