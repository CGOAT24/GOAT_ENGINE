#include "GameObject.h"

GameObject::GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec3 _rotation, const char* _texName): translation(_position.x, _position.y, 0.0f), scale(_scale.x, _scale.y, 0.0f), rotation(_rotation), texture(_texName, "diffuse", 0, GL_UNSIGNED_BYTE), mesh(), shader("default.vert", "default.frag"), light(glm::vec3(_position.x, _position.y, 0.0f)) {
	Vertex vertices[4];

	std::vector<glm::vec2> vertPos = {
		glm::vec2(_position.x - (scale.x / 2), _position.y - (scale.y / 2)),	//bottom left
		glm::vec2(_position.x + (scale.x / 2), _position.y - (scale.y / 2)),	//bottom right
		glm::vec2(_position.x + (scale.x / 2), _position.y + (scale.y / 2)),	//top right
		glm::vec2(_position.x - (scale.x / 2), _position.y + (scale.y / 2))		//top left
	};

	std::vector<glm::vec2> texCoords = {
		glm::vec2(0.0f, 0.0f),													//bottom left
		glm::vec2(1.0f, 0.0f),													//bottom right
		glm::vec2(1.0f, 1.0f),													//top right
		glm::vec2(0.0f, 1.0f)													//top left
	};

	for(int i(0); i < vertPos.size(); i++) {
		glm::vec3 position(vertPos.at(i).x, vertPos.at(i).y, 0.0f);
		glm::vec3 normal(0.0f, 0.0f, -1.0f);
		glm::vec3 color(0.0f, 0.0f, 0.0f);

		Vertex vi{ position, normal, color, texCoords.at(i) };
		vertices[i] = vi;
	}

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));

	this->mesh = Mesh(verts, ind, texture);
	this->light.Activate(shader);
}

glm::vec3 GameObject::getPosition() const {
	return this->translation;
}

glm::vec3 GameObject::getScale() const {
	return glm::vec3();
}

void GameObject::render(Camera& camera) {
	this->mesh.Draw(this->shader, camera);
}

void GameObject::translate(glm::vec2 movement) {
	this->translation.x += movement.x / 1000;
	this->translation.y += movement.y / 1000;
	glm::mat4 model(1.0f);

	model = glm::translate(model, this->translation);
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void GameObject::setScale(glm::vec3 mult) {
	this->scale = mult;
	glm::mat4 model(1.0f);
	model = glm::scale(model, this->scale);
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void GameObject::rotateX(float rotation) {
	this->rotation.x += rotation;
	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void GameObject::rotateY(float rotation) {
	this->rotation.y += rotation;
	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void GameObject::rotateZ(float rotation) {
	this->rotation.z += rotation;
	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}
