#include "gameobj.hpp"
#include "texture_manager.hpp"

Game_obj::Game_obj(const char* texture_sheet) {
	obj_texture = texture_manager::init_texture(texture_sheet);
	
}

Game_obj::~Game_obj(){}

void Game_obj::update(int x, int y) {
	xpos = x;
	ypos = y;

	destination.x = xpos;
	destination.y = ypos;
	destination.w = 140;
	destination.h = 140;
}

void Game_obj::render() {
	SDL_RenderCopy(Game::renderer, obj_texture, NULL, &destination);
}