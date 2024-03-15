#ifndef COMPONENTS
#define COMPONENTS

#include "entt.hpp"
#include "sprite_component.hpp"
#include "position_component.hpp"

class ENTT {
public:
	entt::registry reg;

	void createEntity(entt::entity Entity) {
		Entity = reg.create();
		entity = Entity;
	}

private:
	
	entt::entity entity;
};

#endif