#include "ArenaTestScene.hpp"

ArenaTestScene::ArenaTestScene(Camera* camera, Image* background, uint32_t w, uint32_t h) : Scene(camera, background, w, h) {
	name = "arena_test_scene";
	gravity = 0;
}
