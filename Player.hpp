#ifndef PLAYER
#define PLAYER

#include "components.hpp"

ENTT *entity = new ENTT();

class Player {

private:
	entt::entity player;

	//component variables
	Sprite sprite;
	Position position;

	const char* texture_sheet = "C:\\Users\\angel\\Documents\\video_game_learn\\textures\\mario.png";
	SDL_Rect source, destination;
	SDL_Texture *tex;




public:
	Player() {
		//Put entity in reg
		entity->createEntity(player);


		entity->reg.emplace<Sprite>(player);
		sprite = entity->reg.get<Sprite>(player);
		sprite.init(tex, destination, texture_sheet, 0, 0, 100, 100);

		entity->reg.emplace<Position>(player);
		position = entity->reg.get<Position>(player);
	}

	void update(int x, int y) {
		position.change_position(destination, x, y);
	};

	void render() {
		sprite.render();
	}
};


#endif