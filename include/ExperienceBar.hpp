#pragma once

#include <ProgressBar.hpp>

class ExperienceBar {
public:

	ExperienceBar(Vecf position = Vecf{ 0,0 });
	void draw(Vecf position);
	void add(float exp);
	int current_level = 0;
	float current_exp_points = 0;
	ProgressBar* experience_ui;
};