#ifndef POSITION
#define POSITION

#include "components.hpp"

struct Position {
	int xpos, ypos;

	void change_position(SDL_Rect &destination, int x, int y) {
		xpos = x;
		ypos = y;

		destination.x = xpos;
		destination.y = ypos;

	}
};

#endif