#ifndef GAME
#define GAME

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int w, int h, bool full_screen);
	void handle_events();
	void update();
	void render();
	void clean();

	bool running() { return is_running; };

	static SDL_Renderer* renderer;
private:
	int count;
	bool is_running;
	SDL_Window* window;
};



#endif