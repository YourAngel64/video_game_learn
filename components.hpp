#ifndef COMPONENTS
#define COMPONENTS

#include "ECS.hpp"


class position_component : public Component {
private:
	int xpos;
	int ypos;

public:

	int x() { return xpos; }
	int y() { return ypos; }

	void init() override {
		xpos = 0;
		ypos = 0;
	}

	void update() override {
		xpos++;
		ypos++;
	}

	void set_position(int x, int y) {
		xpos = x;
		ypos = y;
	}


};

#endif