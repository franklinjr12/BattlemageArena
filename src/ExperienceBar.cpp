#include "ExperienceBar.hpp"

#include <AssetsManager.hpp>
#include <Logger.hpp>

const int MAX_LEVEL = 10;
const float level_limits[MAX_LEVEL] = {100,200,300,400,500,600,700,800,900,1000};

ExperienceBar::ExperienceBar(Vecf position) {
	// if use this way the image size will be share with all characters
	//auto img_back = AssetsManager::get_instance()->get_image("progress_bar.png");
	//auto img_front = AssetsManager::get_instance()->get_image("progress_bar_front.png");
	// will need to create new images and not shared
	auto img_front = new Image("assets/exp_bar.png", 1000, 20);
	auto img_back = new Image("assets/progress_bar.png", img_front->width, img_front->height);
	experience_ui = new ProgressBar(position, img_back, img_front, 0);
	experience_ui->set_current(0);
	
}

void ExperienceBar::draw(Vecf position) {
	//experience_ui->pos[0] = position[0];
	//experience_ui->pos[1] = position[1];
	experience_ui->draw();
}

void ExperienceBar::add(float exp) {
	A2D_LOGI("player got {} exp", exp);
	current_exp_points += exp;
	if (current_exp_points > level_limits[MAX_LEVEL - 1]) {
		current_exp_points = level_limits[MAX_LEVEL - 1];
		current_level = MAX_LEVEL;
		experience_ui->set_current(current_exp_points);
		return;
	}
	for (int i = 1; i <= MAX_LEVEL; i++) {
		if (current_exp_points >= level_limits[i-1] && current_exp_points < level_limits[i]) {
			current_level = i;
			break;
		}
	}
	if(current_level > 0)
		experience_ui->set_current(current_exp_points-level_limits[current_level-1]);
	else
		experience_ui->set_current(current_exp_points);
}

