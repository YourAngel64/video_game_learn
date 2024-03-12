#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include "game.hpp"

class texture_manager {
public:
	static SDL_Texture* init_texture(const char* path);
	static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect destination);
};


#endif