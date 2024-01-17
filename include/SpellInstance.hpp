#pragma once

#include <DynamicBody.hpp>
#include <Animation.hpp>

class SpellInstance : public DynamicBody {
public:	
	
	SpellInstance(ObjectId owner, Image* img, Vecf spawn_position, Vecf spawn_speed);
	Animation* animation = nullptr;
	ObjectId owner;
};