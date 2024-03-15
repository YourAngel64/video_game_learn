#ifndef PRUEBA
#define PRUEBA


#include "components.hpp"

//ENTT to create entities in the same reg. Every ENTT varibale need different name
ENTT *entity2 = new ENTT();

//every obj has its own class
class Prueba {

private:
	//Always a entt:entity variable which gonna have ptr of unique value in reg
	entt::entity player;

	//Every component has its own variable to manager values 
	Sprite sprite;

public:
	Prueba() {
		//Put entity in reg
		entity2->createEntity(player);

		//Everytime we emplace a component we do 2 things:
		//1)We emplace it by using the reg directly from ENTT obj.
		//2)We get the values and save it in special private var we created
		entity2->reg.emplace<Sprite>(player);
		sprite = entity2->reg.get<Sprite>(player);
	}

	//Every other function we want for our entity
	void update() {
		sprite.x = 64;
		std::cout << sprite.x << std::endl;
	};

	void render();
};



#endif