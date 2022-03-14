#include "GameObject.h"

/*
Position du gameobject lors de la création à revoir
*/

GOAT_ENGINE::GameObject::GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec3 _rotation, const char* _texName, bool _collider): position(_position.x, _position.y, 0.0f), scale(_scale.x, _scale.y, 0.0f), rotation(_rotation), mesh(), shader("default.vert", "default.frag"), light(glm::vec3(_position.x, _position.y, 0.0f)) {
	Vertex vertices[4];

	glm::vec2 vertPos[] = {
		glm::vec2(position.x - (scale.x / 2.0f), position.y - (scale.y / 2.0f)),
		glm::vec2(position.x + (scale.x / 2.0f), position.y - (scale.y / 2.0f)),
		glm::vec2(position.x + (scale.x / 2.0f), position.y  + (scale.y / 2.0f)),
		glm::vec2(position.x - (scale.x / 2.0f), position.y + (scale.y / 2.0f))
	};

	glm::vec2 texCoords[] = {
		glm::vec2(0.0f, 0.0f),													//bottom left
		glm::vec2(1.0f, 0.0f),													//bottom right
		glm::vec2(1.0f, 1.0f),													//top right
		glm::vec2(0.0f, 1.0f)													//top left
	};

	for(int i(0); i < 4; i++) {
		glm::vec3 position(vertPos[i].x, vertPos[i].y, 0.0f);
		glm::vec3 normal(0.0f, 0.0f, -1.0f);
		glm::vec3 color(0.0f, 0.0f, 0.0f);

		Vertex vi{position, normal, color, texCoords[i]};
		vertices[i] = vi;
	}

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));

	this->collider = Collider(position, scale, _collider);

	Texture texture(_texName, "diffuse", 0, GL_UNSIGNED_BYTE);

	this->mesh = Mesh(verts, ind, texture);
	this->light.Activate(shader);
}

glm::vec3 GOAT_ENGINE::GameObject::getPosition() const {
	return this->position;
}

glm::vec2 GOAT_ENGINE::GameObject::getScale() const {
	return glm::vec2(this->scale.x, this->scale.y);
}

glm::vec3 GOAT_ENGINE::GameObject::getRotation() const
{
	return this->rotation;
}

void GOAT_ENGINE::GameObject::render(Camera& camera) {
	this->mesh.Draw(this->shader, camera);
}

void GOAT_ENGINE::GameObject::translate(glm::vec2 movement) {
	this->position.x += movement.x / 1000.0f;
	this->position.y += movement.y / 1000.0f;

	this->transform();
}

void GOAT_ENGINE::GameObject::setScale(glm::vec2 scale) {
	this->scale = glm::vec3(scale.x, scale.y, 1.0f);

	this->transform();
}

void GOAT_ENGINE::GameObject::rotateX(float rotation) {
	this->rotation.x += rotation;

	this->transform();
}

void GOAT_ENGINE::GameObject::rotateY(float rotation) {
	this->rotation.y += rotation;

	this->transform();
}

void GOAT_ENGINE::GameObject::rotateZ(float rotation) {
	this->rotation.z += rotation;

	this->transform();
}

void GOAT_ENGINE::GameObject::transform() {
	glm::mat4 model(1.0f);
	model = glm::scale(model, this->scale);
	model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, this->position);

	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	this->collider.update(glm::vec2(this->position.x, this->position.y), glm::vec2(this->scale.x, this->scale.y));
}

void GOAT_ENGINE::GameObject::initialize(){

}
