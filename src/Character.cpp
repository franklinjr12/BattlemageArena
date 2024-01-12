#include "Character.hpp"

#include <ArcaneUtils.hpp>

Character::Character() {
}

void Character::_update() {
	if (DistanceVecf(set_position, Vecf{ getX(), getY() }) < POSITION_STOP_THRESHOLD) {
		vel[0] = 0;
		vel[1] = 0;
	}
}

void Character::cast_spell(int spell_num, Vecf direction) {
}
