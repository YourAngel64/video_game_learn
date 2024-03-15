#include "game.hpp"
#include "texture_manager.hpp"
#include "map.hpp"
#include "components.hpp"
#include "all_obj.hpp"

//Registry -> view = reg.view<COMPONENT(S) -> view.get...
// or ... Registry -> reg.get
/*
Para poder aceder a un componente se debe...
1) declare registry:
entt::registry reg;

2)Create entity
auto Player = reg.create();

3)Give entity all its components:
reg.emplace<COMPONENT>(Player);

4)Access component by using get: EACH COMPONENT SHOULD HAVE ITS OWN VARIABLE
auto vel = reg.get<COMPONENT>(Player).COMPONENT_TO_ACCESS


*/

Game::Game() {}
Game::~Game(){}

Map* map;

Player* player = nullptr;


SDL_Renderer* Game::renderer = nullptr;

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
	player = new Player();
	//"C:/Users/angel/Pictures/ugly_art/MC.png"
	
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
	player->update(count, count);
}

void Game::render() {
	SDL_RenderClear(renderer);
	

	map->draw_map();
	player->render();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}