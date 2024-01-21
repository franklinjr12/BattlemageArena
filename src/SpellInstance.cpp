#include "SpellInstance.hpp"
#include "Game.hpp"
#include "Character.hpp"

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
}

void SpellInstance::handle_collision(ObjectId _id){
	Object* obj = game->current_scene->get_body(_id);
	bool is_character = false;
	for (auto& e : obj->groups) {
		if ((ObjectGroup)e == (ObjectGroup)GameGroups::CHARACTER)
			is_character = true;
	}
	if (is_character) {
		Character* c = (Character*)obj;
		c->health -= owner->damage;
	}
}
