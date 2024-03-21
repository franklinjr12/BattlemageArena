#include "MageNPC.hpp"
#include "BasicProjectileSpell.hpp"

#include <AssetsManager.hpp>
#include <Logger.hpp>

MageNPC::MageNPC(Vecf c_pos, Image* c_image, float c_speed, float c_hp) {
	if (c_image == nullptr)
		image = AssetsManager::get_instance()->get_image("simple_mage.png");
	else
		image = c_image;
	rectangle = new BodyRectangle(c_pos, image->width, image->height);
	health_bar = new HealthBar(c_hp);
	setX(c_pos[0]);
	setY(c_pos[1]);
	speed_modifier = c_speed;
	groups.push_back((ObjectGroup)GameGroups::MAGENPC);
	spells.push_back(new BasicProjectileSpell(id));
	attack_distance = magenpc::DEFAULT_ATTACK_DISTANCE;
	attributes.arcane = magenpc::DEFAULT_ARCANE;
}

void MageNPC::attack(Vecf dir) {
	Vecf cast_pos = { getX(),getY() };
	// might need to adjust to the body size
	cast_pos[0] += dir[0] * 50;
	cast_pos[1] += dir[1] * 50;
	for (int i = 0; i < spells.size(); i++) {
		if (!spells[i]->on_cooldown) {
			float total_arcane = attributes.arcane;
			for (auto* i : items)
				total_arcane += i->attributes.arcane;
			spells[i]->cast(cast_pos, dir, total_arcane);
			break;
		}
	}
}
