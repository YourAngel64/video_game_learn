#ifndef MAP
#define MAP

#include "game.hpp"


class Map {

public:

	Map();
	~Map();

	void load_map(int arr[20][25]);
	void draw_map();

private:
	SDL_Rect src, destination;
	SDL_Texture* dirt, *grass, *water;

	int map[20][25];
};


#endif