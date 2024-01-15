#include "Spell.hpp"

#include <EventsManager.hpp>

Spell::Spell(float cooldown_ms) {
	this->cooldown_ms = cooldown_ms;
	name = "spell";
	groups.push_back((ObjectGroup)GameGroups::SPELL);
	timer = new Timer(cooldown_ms);
	EventsManager::getInstance()->subscribe(EventType::Timer, this);
}

bool Spell::cast() {

}

void Spell::process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::Timer:
		ObjectId income_timer = (ObjectId)data[1];
		if (income_timer == id) {
			on_cooldown = false;
		}
	}
}


void Spell::_process_events(std::vector<event_bytes_type> data)
{
}
