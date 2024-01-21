#include "SpellInteraction.hpp"

void SpellInteraction::interact(Spell* s1, Spell* s2) {

}

void SpellInteraction::interact(Spell* s, Character* c) {
	c->health -= s->damage;
}
