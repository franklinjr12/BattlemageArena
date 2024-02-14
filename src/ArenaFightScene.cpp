#include "ArenaFightScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"
#include "GroupsDef.hpp"
#include "NPC.hpp"

#include <ArcaneUtils.hpp>

ArenaFightScene::ArenaFightScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = ARENA_FIGHT_NAME;
	gravity = 0;
}

void ArenaFightScene::_update() {
	std::vector<ObjectId> bodies_to_remove;
	bool arena_cleared = true;
	for (auto* b : bodies) {
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
				game->npc_total_kills++;
				game->experience_gained += ((NPC*)b)->drop_experience;
			}
			if (b->name == "SpellInstance")
				A2D_LOGI("Removing si {}", (uint64_t)b->id);
			bodies_to_remove.push_back(b->id);
		}
	}
	for (ObjectId& b : bodies_to_remove)
		remove_body(b);
	// there are no more NPCs to fight show finish arena screen
	if (arena_cleared) {
		// give exp to the player
		for (auto* b : bodies) {
			ObjectGroup g = (ObjectGroup)GameGroups::PLAYER;
			if (VectorHasGroupId(b->groups, g)) {
				PlayerCharacter* p = (PlayerCharacter*)b;
				p->player_exp->add(game->experience_gained);
				game->experience_gained = 0;
			}
		}
		game->change_scene(ARENA_RESULTS_NAME);
	}
}

void ArenaFightScene::_draw() {
}
