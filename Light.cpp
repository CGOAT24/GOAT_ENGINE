#include "Light.h"

Light::Light(glm::vec3 _position): position(_position), color(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)), model(glm::mat4(1.0f)), shader("light.vert", "light.frag") {
}

Light::Light(glm::vec3 _position, glm::vec4 _color): position(_position), color(_color), model(glm::mat4(1.0f)), shader("light.vert", "light.frag") {
}

void Light::Activate(Shader objShader) {
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), color.x, color.y, color.z, color.w);

	objShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(objShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f))));
	glUniform4f(glGetUniformLocation(objShader.ID, "lightColor"), color.x, color.y, color.z, color.w);
	glUniform3f(glGetUniformLocation(objShader.ID, "lightPos"), position.x, position.y, position.z);
}