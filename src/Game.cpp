#include "Game.hpp"
#include "GroupsDef.hpp"

#include <AssetsManager.hpp>

Game* game = nullptr;

Game::Game() {
	//font = AssetsManager::get_instance()->get_default_font();
	font = AssetsManager::get_instance()->get_default_font();
}

void Game::game_loop() {
	std::vector<ObjectId> bodies_to_remove;
	for (auto* b : current_scene->bodies) {
		for (auto& e : b->groups)
			if (e == (ObjectGroup)GameGroups::MARKDELETE)
				bodies_to_remove.push_back(b->id);
	}
	for (ObjectId& b : bodies_to_remove)
		current_scene->remove_body(b);
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

}
