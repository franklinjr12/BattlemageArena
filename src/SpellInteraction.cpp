#include "SpellInteraction.hpp"
#include "Game.hpp"

void SpellInteraction::interact(Spell* s1, Spell* s2) {

}

void SpellInteraction::interact(Spell* s, Character* c) {
	auto damage_value = s->damage + s->extra_damage;
	c->health -= damage_value;
	c->health_bar->suffer_damage(damage_value);

}
