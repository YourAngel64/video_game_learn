#ifndef GAME_OBJ
#define GAME_OBJ

#include "game.hpp"

class Game_obj {
public:
	Game_obj(const char* texture_sheet);
	~Game_obj();

	void update(int x, int y);
	void render();

private:
	int xpos, ypos;

	SDL_Texture* obj_texture;
	SDL_Rect src, destination;
	
};


#endif