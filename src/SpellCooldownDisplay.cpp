#include "SpellCooldownDisplay.hpp"

#include <AssetsManager.hpp>

SpellCooldownDisplay::SpellCooldownDisplay(Vecf pos, Image* image) : Button(pos, image) {
	background = AssetsManager::get_instance()->get_image("spell_cooldown_background.png");
	foreground = image;
	cooldown_overlay = AssetsManager::get_instance()->get_image("spell_cooldown_overlay.png");
}

void SpellCooldownDisplay::draw() {
	background->draw(pos, background->width, background->height);
	foreground->draw(pos, foreground->width, foreground->height);
	if(on_cooldown)
		cooldown_overlay->draw(pos, RGBA_t{1,1,1,0.5}, cooldown_overlay->width, cooldown_overlay->height);
}
