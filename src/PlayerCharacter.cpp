#include "PlayerCharacter.hpp"

#include <AssetsManager.hpp>

PlayerCharacter::PlayerCharacter() {
	image = new Image(*AssetsManager::get_instance()->get_image("fire_mage.png"));
	int w = 30;
	int h = 60;
	Vecf pos = { 500,500 };
	image->resize(w, h);
	rectangle = new BodyRectangle(pos, w, h);
	setX(pos[0]);
	setY(pos[1]);
}