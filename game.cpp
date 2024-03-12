#include "game.hpp"
#include "texture_manager.hpp"
#include "gameobj.hpp"
#include "map.hpp"
#include "ECS.hpp"
#include "components.hpp"


Game::Game() {}
Game::~Game(){}

Game_obj* player;
Game_obj* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;


Manager manager;
auto& newPlayer(manager.add_entity());

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

	player = new Game_obj("C:/Users/angel/Documents/video_game_learn/textures/mario.png");
	enemy = new Game_obj("C:/Users/angel/Documents/video_game_learn/textures/bowser.png");
	map = new Map();

	newPlayer.add_component<position_component>();
	newPlayer.get_component<position_component>().set_position(500, 500);
	
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
	enemy->update(count * 2, count * 2);
	manager.update();
	std::cout << newPlayer.get_component<position_component>().x() << std::endl;
	std::cout << newPlayer.get_component<position_component>().y() << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	
	//textures to be renderer
	map->draw_map();
	player->render();
	enemy->render();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}