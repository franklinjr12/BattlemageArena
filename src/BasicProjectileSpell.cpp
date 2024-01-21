#include "BasicProjectileSpell.hpp"
#include "SpellInstance.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

BasicProjectileSpell::BasicProjectileSpell(ObjectId owner) : Spell(DEFAULT_TIMEOUT) {
	this->owner = owner;
	name = "BasicProjectileSpell";
	image = AssetsManager::get_instance()->get_image("basic_spell.png");
	set_cooldown(DEFAULT_TIMEOUT); // it is needed as a workaround for now
	damage = 10;
}

void BasicProjectileSpell::_cast(Vecf position, Vecf dir) {
	Vecf vel;
	vel[0] = dir[0] * projectile_velocity;
	vel[1] = dir[1] * projectile_velocity;
	SpellInstance* spell = new SpellInstance(this, image, position, vel);
	game->current_scene->add_body(spell);
}