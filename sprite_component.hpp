#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include "components.hpp"

struct Sprite {

	SDL_Texture* ola;
	SDL_Rect noc;

	void init() {
		std::cout << "ola";
		ola = texture_manager::init_texture("ss");
		noc.h = 200;
		noc.w = 200;
	}

	void update(SDL_Renderer* ren) {
		SDL_RenderCopy(ren, ola, NULL, &noc);
	}
	int x;

};


#endif