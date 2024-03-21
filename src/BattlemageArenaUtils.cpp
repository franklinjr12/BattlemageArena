#include "BattlemageArenaUtils.hpp"
#include "BattlemageArenaConstants.hpp"
#include "Game.hpp"

#include <chrono>
#include <random>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);

int get_gold_from_current_kill() {
    int max_value = 1;
    int min_value = 1;
    std::string current_arena_difficulty = game->arena_results_stats.difficulty;
    if (current_arena_difficulty == ARENA_DIFFICULTY_EASY) {
        max_value = 1;
    }
    else if (current_arena_difficulty == ARENA_DIFFICULTY_NORMAL) {
        max_value = 2;
    }
    else if (current_arena_difficulty == ARENA_DIFFICULTY_HARD) {
        max_value = 3;
    }
    std::uniform_int_distribution<int> gold_distribution(min_value, max_value);
    return gold_distribution(generator);
}

int get_exp_from_current_kill() {
    int max_value = 10;
    int min_value = 10;
    std::string current_arena_difficulty = game->arena_results_stats.difficulty;
    if (current_arena_difficulty == ARENA_DIFFICULTY_EASY) {
        max_value = 10;
    }
    else if (current_arena_difficulty == ARENA_DIFFICULTY_NORMAL) {
        max_value = 20;
    }
    else if (current_arena_difficulty == ARENA_DIFFICULTY_HARD) {
        max_value = 30;
    }
    std::uniform_int_distribution<int> exp_distribution(min_value, max_value);
    return exp_distribution(generator);
}
