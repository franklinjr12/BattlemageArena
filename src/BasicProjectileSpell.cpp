#include "BasicProjectileSpell.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

BasicProjectileSpell::BasicProjectileSpell() : Spell(cooldown_ms) {
	name = "BasicProjectileSpell";
	image = AssetsManager::get_instance()->get_image("basic_spell.png");
	// put rectangle out of screen, it will be set when cast() is called
	rectangle = new BodyRectangle(Vecf{-200,-200}, image->width, image->height);
	cooldown_ms = 2000;
	damage = 1;
}

void BasicProjectileSpell::_cast(Vecf position, Vecf dir) {
	vel[0] = dir[0] * projectile_velocity;
	vel[1] = dir[1] * projectile_velocity;
	DynamicBody* physical_spell = new DynamicBody(image, rectangle);
	physical_spell->vel[0] = vel[0];
	physical_spell->vel[1] = vel[1];
	game->current_scene->add_body(physical_spell);
	//game->current_scene->add_body(new BasicProjectileSpell(*this));
}