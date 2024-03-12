#include "game.hpp"
#define SDL_main main

Game* game = nullptr;

//Control framerate

const int FPS = 60;
const int frame_delay = 1000 / 60;
Uint32 frame_start;
int frame_time;

int main(int argc, const char* argv[]) {
	game = new Game();
	game->init("TUTORIAL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);

	while (game->running()) {
		frame_start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time) {
			SDL_Delay(frame_delay - frame_time);
		}
	}

	game->clean();


	return 0;
}