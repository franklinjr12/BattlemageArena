#include "HealthBar.hpp"

#include <AssetsManager.hpp>

HealthBar::HealthBar(float initial_hp, Vecf position) {
	// if use this way the image size will be share with all characters
	//auto img_back = AssetsManager::get_instance()->get_image("progress_bar.png");
	//auto img_front = AssetsManager::get_instance()->get_image("progress_bar_front.png");
	// will need to create new images and not shared
	auto img_back = new Image("assets/progress_bar.png");
	auto img_front = new Image("assets/progress_bar_front.png");
	health_ui = new ProgressBar(position, img_back, img_front, 0, initial_hp);
	current_health_points = initial_hp;
}

void HealthBar::draw(Vecf position) {
	health_ui->pos[0] = position[0];
	health_ui->pos[1] = position[1];
	health_ui->draw();
}

void HealthBar::suffer_damage(float damage){
	current_health_points -= damage;
	if (current_health_points < 0) current_health_points = 0;
	health_ui->set_current(current_health_points);
}

float HealthBar::get_hp() {
	return current_health_points;
}
