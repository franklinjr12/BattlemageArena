#include "ArenaFightSceneFactory.hpp"

#include "BattlemageArenaConstants.hpp"
#include "NPC.hpp"
#include "CreatureNPCFactory.hpp"
#include "MageNPCFactory.hpp"
#include "Game.hpp"

#include <AssetsManager.hpp>

ArenaFightScene* ArenaFightSceneFactory::create(std::string difficulty) {
    int num_creatures = 0;
    int num_mages = 1;
    if (difficulty == ARENA_DIFFICULTY_EASY) {
        num_creatures = 0;
        num_mages = 1;
    }
    else if (difficulty == ARENA_DIFFICULTY_NORMAL) {
        num_creatures = 4;
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
    // need some care to not generate enemies in the correct position
    for (int i = 0; i < num_creatures; i++)
        scene->add_body(CreatureNPCFactory::create());
    for (int i = 0; i < num_mages; i++)
        scene->add_body(MageNPCFactory::create());
    return scene;
}
