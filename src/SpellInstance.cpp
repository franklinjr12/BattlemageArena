#include "SpellInstance.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "SpellInteraction.hpp"

#include <Logger.hpp>

SpellInstance::SpellInstance(Spell* owner, Image* img, Vecf spawn_position, Vecf spawn_speed, float lifetime_ms) {
	name = "SpellInstance";
	this->owner = owner;
	image = img;
	rectangle = new BodyRectangle(spawn_position, img->width, img->height);
	vel[0] = spawn_speed[0];
	vel[1] = spawn_speed[1];
	setX(spawn_position[0]);
	setY(spawn_position[1]);
	groups.push_back((ObjectGroup)GameGroups::SPELLINSTANCE);
	lifetime_timer = new Timer(lifetime_ms);
	EventsManager::getInstance()->subscribe(EventType::Timer, this);
	lifetime_timer->start();
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

void SpellInstance::process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::Timer:
		ObjectId income_timer = (ObjectId)data[1];
		if (income_timer == lifetime_timer->id) {
			groups.push_back((ObjectGroup)GameGroups::MARKDELETE);
			A2D_LOGI("SpellInstance id {} marked to delete", id);
		}
	}
}