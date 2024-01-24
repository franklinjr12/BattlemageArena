#pragma once

#include "Character.hpp"
#include "SpellCooldownDisplay.hpp"
#include "ExperienceBar.hpp"

#include <array>

#define PLAYER_SHOW_SPELLS_NUM 4

class PlayerCharacter : public Character {
public:

	PlayerCharacter();

	void process_events(std::vector<event_bytes_type> data);
	void _draw() override;
	void _update();

	const float PLAYER_DEFAULT_VELOCITY = 4;
	Image* player_right;
	Image* player_left;
	ExperienceBar* player_exp;
	std::array<SpellCooldownDisplay*, PLAYER_SHOW_SPELLS_NUM> spells_ui;
};