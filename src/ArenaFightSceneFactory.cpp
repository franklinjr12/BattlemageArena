#include "ArenaFightSceneFactory.hpp"

#include "BattlemageArenaConstants.hpp"
#include "NPC.hpp"
#include "CreatureNPCFactory.hpp"
#include "MageNPCFactory.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>
#include <vector>

ArenaFightScene* ArenaFightSceneFactory::create(std::string difficulty) {
    int num_creatures = 0;
    int num_mages = 1;
    if (difficulty == ARENA_DIFFICULTY_EASY) {
        num_creatures = 0;
        num_mages = 1;
    }
    else if (difficulty == ARENA_DIFFICULTY_NORMAL) {
        num_creatures = 3;
        num_mages = 0;
    }
    else if (difficulty == ARENA_DIFFICULTY_HARD) {
        num_creatures = 2;
        num_mages = 1;
    }
    Camera* camera = new Camera(0, 0, game->width, game->height);
    Image* background = AssetsManager::get_instance()->get_image("battle_arena.png");
    background->resize(game->width, game->height);
    auto* scene = new ArenaFightScene(camera, background, game->width, game->height);
    game->arena_results_stats.difficulty = difficulty;
    std::vector<float*> enemies_positions;
    int enemies_positions_index = 0;
    enemies_positions.push_back(Vecf{ (float)game->width / 2 - game->width / 5, (float)game->height / 2 });
    enemies_positions.push_back(Vecf{ (float)game->width / 2 , (float)game->height / 2 - game->height / 5 });
    enemies_positions.push_back(Vecf{ (float)game->width / 2 + game->width / 5, (float)game->height / 2 });
    enemies_positions.push_back(Vecf{ (float)game->width / 2 , (float)game->height / 2  + game->height / 5});
    // need some care to not generate enemies in the correct position
    for (int i = 0; i < num_creatures; i++, enemies_positions_index++) {
        scene->add_body(CreatureNPCFactory::create(enemies_positions[enemies_positions_index]));
    }
    for (int i = 0; i < num_mages; i++, enemies_positions_index++) {
        scene->add_body(MageNPCFactory::create(enemies_positions[enemies_positions_index]));
    }
    return scene;
}
