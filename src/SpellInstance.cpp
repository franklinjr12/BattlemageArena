#include "SpellInstance.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "SpellInteraction.hpp"

#include <algorithm>

//SpellInstance::SpellInstance(ObjectId owner, Image* img, Vecf spawn_position, Vecf spawn_speed) {
SpellInstance::SpellInstance(Spell* owner, Image* img, Vecf spawn_position, Vecf spawn_speed) {
	this->owner = owner;
	image = img;
	rectangle = new BodyRectangle(spawn_position, img->width, img->height);
	vel[0] = spawn_speed[0];
	vel[1] = spawn_speed[1];
	setX(spawn_position[0]);
	setY(spawn_position[1]);
	groups.push_back((ObjectGroup)GameGroups::SPELLINSTANCE);
}

void SpellInstance::handle_collision(ObjectId _id) {
	Object* obj = game->current_scene->get_body(_id);
	for (auto& e : obj->groups) {
		if ((ObjectGroup)e == (ObjectGroup)GameGroups::CHARACTER) {
			auto* c = (Character*)obj;
			if (owner->owner != c->id) {
				SpellInteraction::interact(owner, c);
				groups.push_back((ObjectGroup)GameGroups::MARKDELETE);
			}
		}
		if ((ObjectGroup)e == (ObjectGroup)GameGroups::SPELL)
			SpellInteraction::interact(owner, (Spell*)obj);
	}
}
