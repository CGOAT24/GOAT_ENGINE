#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H

#include "Light.h"

class GameObject {
protected:
	Mesh mesh;
	Shader shader;
	Light light;

	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	void transform();

public:
	GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec3 _rotation, const char* _texName);
	glm::vec3 getPosition() const;
	glm::vec2 getScale() const;
	glm::vec3 getRotation() const;

	void render(Camera& camera);
	void translate(glm::vec2 movement);
	void setScale(glm::vec2 scale);
	void rotateX(float rotation);
	void rotateY(float rotation);
	void rotateZ(float rotation);
};

#endif