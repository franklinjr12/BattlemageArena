#include "Game.hpp"
#include "GroupsDef.hpp"
#include "NPC.hpp"
#include "BattlemageArenaConstants.hpp"

#include <AssetsManager.hpp>

Game* game = nullptr;

Game::Game() {
	font = AssetsManager::get_instance()->get_default_font();
}

void Game::game_loop() {
	if (current_scene->name == ARENA_FIGHT_NAME) {
		std::vector<ObjectId> bodies_to_remove;
		bool arena_cleared = true;
		for (auto* b : current_scene->bodies) {
			// check if there is still at least one NPC, if not level is completed
			ObjectGroup g = (ObjectGroup)GameGroups::NPC;
			if (VectorHasGroupId(b->groups, g)) {
				arena_cleared = false;
			}
			g = (ObjectGroup)GameGroups::MARKDELETE;
			if (VectorHasGroupId(b->groups, g)) {
				// if is a NPC should give some exp to player				
				g = (ObjectGroup)GameGroups::NPC;
				if (VectorHasGroupId(b->groups, g)) {
					npc_total_kills++;
					experience_gained += ((NPC*)b)->drop_experience;
				}
				if (b->name == "SpellInstance")
					A2D_LOGI("Removing si {}", (uint64_t)b->id);
				bodies_to_remove.push_back(b->id);
			}
		}
		for (ObjectId& b : bodies_to_remove)
			current_scene->remove_body(b);
		// there are no more NPCs to fight show finish arena screen
		if (arena_cleared) {
			// give exp to the player
			for (auto* b : current_scene->bodies) {
				ObjectGroup g = (ObjectGroup)GameGroups::PLAYER;
				if (VectorHasGroupId(b->groups, g)) {
					PlayerCharacter* p = (PlayerCharacter*)b;
					p->player_exp->add(experience_gained);
					experience_gained = 0;
				}
			}
			current_scene = arena_results_scene;
		}
	}
	if (current_scene->name == ARENA_FIGHT_NAME) {

	}
}

void Game::game_draw() {
	Vecf pos;
	pos[0] = 10;
	pos[1] = 40;
	const int buf_size = 128;
	char text_buffer[buf_size];
	sprintf_s(text_buffer, "mx: %03d my: %03d", (int)mouse_pos[0], (int)mouse_pos[1]);
	font->print(pos, (char*)text_buffer);
	pos[1] += 20;
	//sprintf_s(text_buffer, "px: %03d py: %03d", (int)player->getX(), (int)player->getY());
	//font->print(pos, (char*)text_buffer);
	Point p;
	p.x = mouse_pos[0];
	p.y = mouse_pos[1];
	for (auto* b : current_scene->bodies) {
		if (isPointRectColliding(*b->rectangle, p)) {
			sprintf_s(text_buffer, "id: %lu", (uint64_t)b->id);
			font->print(p.pos, (char*)text_buffer, FULL_WHITE);
		}
	}
}
