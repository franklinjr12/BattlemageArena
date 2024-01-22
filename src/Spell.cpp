#include "Spell.hpp"

#include <EventsManager.hpp>

Spell::Spell(float cooldown_ms) {
	this->cooldown_ms = cooldown_ms;
	name = "spell";
	groups.push_back((ObjectGroup)GameGroups::SPELL);
	timer = new Timer(cooldown_ms);
	EventsManager::getInstance()->subscribe(EventType::Timer, this);
	image = nullptr;
	spell_ui = nullptr;
}

bool Spell::cast(Vecf position, Vecf dir) {
	if (on_cooldown)
		return false;
	on_cooldown = true;
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

void Spell::set_cooldown(float ms){
	timer->stop();
	delete timer;
	timer = new Timer(ms);
}

float Spell::get_cooldown(){
	return cooldown_ms;
}

