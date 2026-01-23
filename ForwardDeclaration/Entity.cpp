#include "Entity.h"
#include "Vector.h"

Entity::Entity(int x, int y) {
	position = new Vector();
	position->x = x;
	position->y = y;
}

Entity::~Entity() {
	if (position) {
		delete position;
		position = nullptr;
	}
}

