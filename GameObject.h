#pragma once

#include "Mesh.h"

class GameObject {
protected:
	Mesh mesh;
	Texture texture;

	glm::vec2 position;
	glm::vec2 scale;
	glm::vec2 rotation;

public:
	GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec2 _rotation, const Texture _textures);
};

