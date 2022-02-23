#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H

#include "Light.h"

class GameObject {
protected:
	Mesh mesh;
	Texture texture;
	Shader shader;
	Light light;

	glm::vec2 position;
	glm::vec2 scale;
	glm::vec2 rotation;

public:
	GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec2 _rotation, const char* _texName);
	void render(Camera& camera);
	~GameObject();
	void translate(glm::mat4 mat);
	void setScale(glm::vec2 scaleMult);
	void rotate(glm::vec2 rotation);
};

#endif