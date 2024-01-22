#pragma once

#include "Button.hpp"

class SpellCooldownDisplay : public Button {
public:

	SpellCooldownDisplay(Vecf pos, Image* image);
	void draw() override;

	Image* background = nullptr;
	Image* foreground = nullptr;
	Image* cooldown_overlay = nullptr;
	bool on_cooldown = false;
};