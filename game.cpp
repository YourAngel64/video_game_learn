#include "game.hpp"
#include "texture_manager.hpp"
#include "map.hpp"
#include "components.hpp"

//Registry -> view = reg.view<COMPONENT(S) -> view.get...
// or ... Registry -> reg.get

Game::Game() {}
Game::~Game(){}

Map* map;

SDL_Renderer* Game::renderer = nullptr;

entt::registry reg;



auto Player = reg.create();

void Game::init(const char* title, int xpos, int ypos, int w, int h, bool full_screen) {
	int flags = 0;
	if (full_screen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		//Init window and renderer
		window = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		//set renderer white
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		is_running = true;
	}
	else {
		is_running = false;
	}

	map = new Map();
	//"C:/Users/angel/Pictures/ugly_art/MC.png"
	reg.emplace<Sprite>(Player);
}

void Game::handle_events() {
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
	}
}


void Game::update() {
	count++;
}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_Rect destination;
	destination.h = 100;
	destination.w = 100;
	//textures to be renderer
	map->draw_map();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}