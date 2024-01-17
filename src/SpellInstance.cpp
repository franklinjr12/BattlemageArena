#include "SpellInstance.hpp"

SpellInstance::SpellInstance(ObjectId owner, Image* img, Vecf spawn_position, Vecf spawn_speed) {
	this->owner = owner;
	image = img;
	rectangle = new BodyRectangle(spawn_position, img->width, img->height);
	vel[0] = spawn_speed[0];
	vel[1] = spawn_speed[1];
	setX(spawn_position[0]);
	setY(spawn_position[1]);
}