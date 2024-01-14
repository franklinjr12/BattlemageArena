#include "BasicProjectileSpell.hpp"

#include <AssetsManager.hpp>

BasicProjectileSpell::BasicProjectileSpell(Vecf pos, Vecf v) {
	image = AssetsManager::get_instance()->get_image("basic_spell.png");
	rectangle = new BodyRectangle(pos, image->width, image->height);
	setX(pos[0]);
	setY(pos[1]);
	vel[0] = v[0];
	vel[1] = v[1];
}