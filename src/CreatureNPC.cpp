#include "CreatureNPC.hpp"
#include "BasicAttackSpell.hpp"

#include <AssetsManager.hpp>
#include <Logger.hpp>

CreatureNPC::CreatureNPC(Vecf c_pos, Image* c_image, float c_damage, float c_speed, float c_hp) {
	if (c_image == nullptr)
		image = AssetsManager::get_instance()->get_image("big_demon_run_anim_f3.png");
	else
		image = c_image;
	rectangle = new BodyRectangle(c_pos, image->width, image->height);
	health_bar = new HealthBar(c_hp);
	setX(c_pos[0]);
	setY(c_pos[1]);
	attack_damage = c_damage;
	speed_modifier = c_speed;
	groups.push_back((ObjectGroup)GameGroups::CREATURENPC);
	spells.push_back(new BasicAttackSpell(id));
}

void CreatureNPC::attack(Vecf dir){
	Vecf cast_pos = { getX(),getY() };
	//if (dir[0] > 0)
	//	cast_pos[0] += rectangle->w * 1.5;
	//else
	//	cast_pos[0] -= rectangle->w * 1.5;
	cast_pos[0] += dir[0] * 50;
	cast_pos[1] += dir[1] * 50;
	// damage scalling with attribute
	float total_arcane = attributes.arcane;
	for (auto i : items)
		total_arcane += i.attributes.arcane;
	spells[0]->cast(cast_pos, dir, total_arcane);
}
