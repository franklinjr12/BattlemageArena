#include "SpellInteraction.hpp"
#include "Game.hpp"

void SpellInteraction::interact(Spell* s1, Spell* s2) {

}

void SpellInteraction::interact(Spell* s, Character* c) {
	c->health -= s->damage;
	c->health_bar->suffer_damage(s->damage);

}
