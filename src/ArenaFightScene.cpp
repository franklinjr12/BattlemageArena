#include "ArenaFightScene.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"
#include "GroupsDef.hpp"
#include "NPC.hpp"
#include "CombatTimer.hpp"

#include <ArcaneUtils.hpp>
#include <chrono>
#include <random>

CombatTimer* cb;

ArenaFightScene::ArenaFightScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = ARENA_FIGHT_NAME;
	gravity = 0;
	cb = new CombatTimer(120);
	uis.push_front(cb);
}

ArenaFightScene::~ArenaFightScene() {
	// should clear all created objects
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
				game->arena_results_stats.enemies_killed++;
				game->arena_results_stats.experience_earned += ((NPC*)b)->drop_experience;
			}
			if (b->name == "SpellInstance")
				A2D_LOGI("Removing si {}", (uint64_t)b->id);
			bodies_to_remove.push_back(b->id);
		}
	}
	for (ObjectId& b : bodies_to_remove)
		remove_body(b);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gold_distribution(1, 5);
	std::uniform_int_distribution<int> exp_distribution(40, 60);
	game->arena_results_stats.experience_earned = exp_distribution(generator);
	// there are no more NPCs to fight show finish arena screen
	if (arena_cleared) {
		// give exp to the player
		PlayerCharacter* p = game->player;
		auto current_level = p->player_exp->current_level;
		p->player_exp->add(game->arena_results_stats.experience_earned);
		auto new_level = p->player_exp->current_level;
		if (current_level < new_level) {
			p->attributes.points++;
		}
		// fill arena cleared stats
		game->arena_results_stats.cleared_time = cb->elapsed_time;
		// enemies killed is already done
		// difficulty is already done
		//game->arena_results_stats.gold_earned = gold_earned;
		game->arena_results_stats.gold_earned = gold_distribution(generator);
		game->player->gold += game->arena_results_stats.gold_earned;
		// expererience is already done
		game->change_scene(ARENA_RESULTS_NAME);
	}
}

void ArenaFightScene::_draw() {
}
