#ifndef LIGHT_CLASS_H
#define LIGHT_CLASS_H

#include "Mesh.h"

class Light {
public:
	glm::vec3 position;
	glm::vec4 color;
	glm::mat4 model;
	Shader shader;
	Mesh light;
	
	Light();
	Light(glm::vec4 _color);
	void Activate(Shader objShader);
};

#endif