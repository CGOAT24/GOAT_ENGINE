#ifndef COLLIDER_CLASS_H
#define COLLIDER_CLASS_H

#include <iostream>
#include <string>
#include <glm/glm.hpp>

class Collider {
private:
	glm::vec2 position;
	glm::vec2 size;
	bool isActive;

public:
	Collider();
	Collider(glm::vec2 _position, glm::vec2 _size, bool _active);
	void update(glm::vec2 newPos, glm::vec2 newSize);
	bool isColliding(Collider other);
	void setActive(bool active);
};
#endif