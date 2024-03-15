#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include "components.hpp"
#include "SDL.h"
#include "texture_manager.hpp"

struct Sprite {

	SDL_Rect src, *des;
	SDL_Texture *text;

	void init(SDL_Texture *texture, SDL_Rect &destination, const char* tex, int x, int y, int w, int h) {
		texture = texture_manager::init_texture(tex);
		text = texture;

		destination.x = x;
		destination.y = y;

		destination.h = h;
		destination.w = w;

		des = &destination;
	}

	void render() {
		texture_manager::draw(text, src, *des);
	}
};


#endif