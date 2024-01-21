#pragma once

#include "Spell.hpp"

#include <DynamicBody.hpp>
#include <Animation.hpp>

class SpellInstance : public DynamicBody {
public:	
	
	//SpellInstance(ObjectId owner, Image* img, Vecf spawn_position, Vecf spawn_speed);
	SpellInstance(Spell* owner, Image* img, Vecf spawn_position, Vecf spawn_speed);
	virtual void handle_collision(ObjectId _id);
	Animation* animation = nullptr;
	//ObjectId owner;
	Spell* owner;
};