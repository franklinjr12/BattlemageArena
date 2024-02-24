#pragma once

#include "ArenaFightScene.hpp"

class ArenaFightSceneFactory {
public:

	static ArenaFightScene* create(std::string difficulty);
};

