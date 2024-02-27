#include "Character.hpp"

#include <ArcaneUtils.hpp>
#include <Logger.hpp>
#include <EventsManager.hpp>

Character::Character() {
	groups.push_back((ObjectGroup)GameGroups::CHARACTER);
	dash.dash_timer = new Timer(dash_cooldown_ms);
}

void Character::_draw() {
	if (health_bar->health_ui->should_draw) {
		Vecf offset = { getX(), getY() - image->height };
		health_bar->draw(offset);
	}
}

void Character::_update() {
	if (DistanceVecf(set_position, Vecf{ getX(), getY() }) < POSITION_STOP_THRESHOLD) {
		vel[0] = 0;
		vel[1] = 0;
	}
}

void Character::cast_spell(int spell_num, Vecf direction) {
	if (spells.size() >= spell_num) {
		Vecf offset; // to make so that the spell is off character body
		//offset[0] = getX() + 10 * direction[0];
		//offset[1] = getY() + 10 * direction[1];
		offset[0] = getX() + (direction[0] > 0 ? image->width / 2 : -image->width / 2);
		offset[1] = getY();// +(direction[1] > 0 ? image->height / 2 : -image->height / 2);
		//offset[1] = getY() + (direction[1] > 0 ? image->height/2 : -image->height/2);
		spells[spell_num]->cast(offset, direction);
	}
}

void Character::attack(Vecf dir) {
}

bool Character::do_dash(Vecf dash_direction) {
	if (dash.cast()) {
		Vecf final_position;
		final_position[0] = getX() + dash_direction[0] * DEFAULT_VELOCITY * 20;
		setX(final_position[0]);
		final_position[1] = getY() + dash_direction[1] * DEFAULT_VELOCITY * 20;
		setY(final_position[1]);
		return true;
	}
	return false;
}

CharacterDash::CharacterDash() {
	EventsManager::getInstance()->subscribe(EventType::Timer, this);
}

bool CharacterDash::cast() {
	if (on_cooldown) {
		return false;
	}
	on_cooldown = true;
	dash_timer->reset();
	return true;
}

void CharacterDash::process_events(std::vector<event_bytes_type> data) {
	switch (data[0]) {
	case (event_bytes_type)EventType::Timer:
		ObjectId income_timer = (ObjectId)data[1];
		if (income_timer == dash_timer->id) {
			A2D_LOGI("Dash of creature id {} off cooldown", id);
			on_cooldown = false;
		}
	}
}
