#include "Character.hpp"

#include <ArcaneUtils.hpp>

Character::Character() {
	groups.push_back((ObjectGroup)GameGroups::CHARACTER);
}

void Character::_draw(){
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
		offset[0] = getX() + (direction[0] > 0 ? image->width/2 : -image->width/2);
		offset[1] = getY();// +(direction[1] > 0 ? image->height / 2 : -image->height / 2);
		//offset[1] = getY() + (direction[1] > 0 ? image->height/2 : -image->height/2);
		spells[spell_num]->cast(offset, direction);
	}
}

void Character::attack(Vecf dir) {
}
