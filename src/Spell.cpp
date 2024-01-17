#include "Spell.hpp"

#include <EventsManager.hpp>
#include <chrono>

Spell::Spell(float cooldown_ms) {
	this->cooldown_ms = cooldown_ms;
	name = "spell";
	groups.push_back((ObjectGroup)GameGroups::SPELL);
	timer = new Timer(cooldown_ms);
	EventsManager::getInstance()->subscribe(EventType::Timer, this);
	image = nullptr;
	rectangle = nullptr;
}

bool Spell::cast(Vecf position, Vecf dir) {
	if (on_cooldown)
		return false;
	on_cooldown = true;
	setX(position[0]);
	setY(position[1]);
	direction[0] = dir[0];
	direction[1] = dir[1];
	_cast(position, dir);
	timer->reset();
}

void Spell::process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::Timer:
		ObjectId income_timer = (ObjectId)data[1];
		if (income_timer == timer->id) {
			on_cooldown = false;
		}
	}
	_process_events(data);
}

