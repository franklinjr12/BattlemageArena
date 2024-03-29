#include "BasicAttackSpell.hpp"
#include "SpellInstance.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

BasicAttackSpell::BasicAttackSpell(ObjectId owner) : Spell(DEFAULT_TIMEOUT) {
	this->owner = owner;
	name = "BasicAttackSpell";
	image = AssetsManager::get_instance()->get_image("basic_attack_spell.png");
	spell_ui = AssetsManager::get_instance()->get_image("basic_attack_spell_ui.png");
	set_cooldown(DEFAULT_TIMEOUT); // it is needed as a workaround for now
	damage = DEFAULT_DAMAGE;
	lifetime_ms = 100;
}

void BasicAttackSpell::_cast(Vecf position, Vecf dir) {
	Vecf vel;
	vel[0] = dir[0] * projectile_velocity;
	vel[1] = dir[1] * projectile_velocity;
	SpellInstance* spell = new SpellInstance(this, image, position, vel, lifetime_ms);
	A2D_LOGI("SpellInstance id {} added", spell->id);
	game->current_scene->add_body(spell);
}