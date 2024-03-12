#include "texture_manager.hpp"

SDL_Texture *texture_manager::init_texture(const char* path){
	SDL_Surface* temp_surface = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	return tex;
}

void texture_manager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect destination) {
	SDL_RenderCopy(Game::renderer, tex, NULL, &destination);
}