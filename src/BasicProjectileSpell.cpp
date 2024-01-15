#include "BasicProjectileSpell.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

BasicProjectileSpell::BasicProjectileSpell() : Spell(cooldown_ms) {
	name = "BasicProjectileSpell";
	image = AssetsManager::get_instance()->get_image("basic_spell.png");
	// put rectangle out of screen, it will be set when cast() is called
	rectangle = new BodyRectangle(Vecf{-200,-200}, image->width, image->height);
}

void BasicProjectileSpell::_cast(Vecf position, Vecf dir) {
	vel[0] = dir[0] * projectile_velocity;
	vel[1] = dir[1] * projectile_velocity;
	game->current_scene->add_body(this);
}