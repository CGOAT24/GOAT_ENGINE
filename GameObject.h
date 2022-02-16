#pragma once

#include "Mesh.h"

class GameObject {
protected:
	Mesh mesh;
	Texture textures[2];

	glm::vec2 position;
	glm::vec2 size;
	glm::vec2 rotation;

public:
	GameObject(glm::vec2 _position, glm::vec2 _size, glm::vec2 _rotation, Texture _textures[2]);
};

