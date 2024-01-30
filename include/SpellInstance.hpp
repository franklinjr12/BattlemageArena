#pragma once

#include "Spell.hpp"

#include <DynamicBody.hpp>
#include <Animation.hpp>

class SpellInstance : public DynamicBody {
public:	
	
	//SpellInstance(ObjectId owner, Image* img, Vecf spawn_position, Vecf spawn_speed);
	SpellInstance(Spell* owner, Image* img, Vecf spawn_position, Vecf spawn_speed, float lifetime_ms = 2000);
	virtual void process_events(std::vector<event_bytes_type> data) override;
	virtual void handle_collision(ObjectId _id) override;
	Animation* animation = nullptr;
	//ObjectId owner;
	Spell* owner;
	Timer* lifetime_timer;

};