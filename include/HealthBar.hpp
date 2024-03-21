#pragma once

#include <ProgressBar.hpp>

class HealthBar {
public:

	HealthBar(float initial_hp = 100, Vecf position = Vecf{0,0});
	void draw(Vecf position);
	void suffer_damage(float damage);
	float get_hp();
	float get_max_hp();
	void add_hp(float points);

	float current_health_points;
	ProgressBar* health_ui;
};