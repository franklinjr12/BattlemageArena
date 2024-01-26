#include "CombatTimer.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <stdio.h>

using namespace std::chrono;

std::string convert_time_to_s(system_clock::duration d) {
	auto c = duration_cast<seconds>(d).count();
	char buffer[10];
	sprintf(buffer, "%3ds", c);
	return std::string(buffer);
}

CombatTimer::CombatTimer(int time_s) {
	combat_time = time_s * 1s;
	start_time = system_clock::now();
	auto end_time = start_time + combat_time;
	auto cur = end_time - system_clock::now();
	std::string s = convert_time_to_s(cur);
	auto* font = AssetsManager::get_instance()->get_default_font();
	auto* image = AssetsManager::get_instance()->get_image("combat_timer_ui.png");
	Vecf pos = { game->width / 2, 100 };
	td = new TextDisplay(pos, image, s, font);
	rect = new BodyRectangle(pos, image->width, image->height);
}

void CombatTimer::draw() {
	auto cur = start_time + combat_time - system_clock::now();
	td->text = convert_time_to_s(cur);
	td->draw();
}
