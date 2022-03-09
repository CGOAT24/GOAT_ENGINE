#include "GameObject.h"


void GameObject::transform() {
	glm::mat4 model(1.0f);
	model = glm::scale(model, this->scale);
	model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, this->position);
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

/// <summary>
/// Constructeur pour la classe GameObject
/// </summary>
/// <param name="_position"></param>
/// <param name="_scale"></param>
/// <param name="_rotation"></param>
/// <param name="_texName"></param>
GameObject::GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec3 _rotation, const char* _texName): position(_position.x, _position.y, 0.0f), scale(_scale.x, _scale.y, 0.0f), rotation(_rotation), mesh(), shader("default.vert", "default.frag"), light(glm::vec3(_position.x, _position.y, 0.0f)) {
	std::cout << "Render start" << _texName << std::endl;
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
	std::cout << "Render start"<< _texName <<std::endl;

	Texture texture(_texName, "diffuse", GL_TEXTURE0, GL_UNSIGNED_BYTE);
	this->mesh = Mesh(verts, ind, texture);
	std::cout << "Render start" << _texName << std::endl;
	std::cout << "Render stop" << std::endl;
	this->light.Activate(shader);

	this->rotateX(_rotation.x);
	this->rotateY(_rotation.y);
	this->rotateZ(_rotation.z);

	glm::mat4 model(1.0f);
	model = glm::translate(model, this->position);
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

glm::vec3 GameObject::getPosition() const {
	return this->position;
}

glm::vec2 GameObject::getScale() const {
	return glm::vec2(this->scale.x, this->scale.y);
}

glm::vec3 GameObject::getRotation() const
{
	return this->rotation;
}

void GameObject::render(Camera& camera) {
	this->mesh.Draw(this->shader, camera);
}

void GameObject::translate(glm::vec2 movement) {
	this->position.x += movement.x / 1000;
	this->position.y += movement.y / 1000;

	this->transform();
}

void GameObject::setScale(glm::vec2 scale) {
	this->scale = glm::vec3(scale.x, scale.y, 1.0f);

	this->transform();
}

void GameObject::rotateX(float rotation) {
	this->rotation.x += rotation;

	this->transform();
}

void GameObject::rotateY(float rotation) {
	this->rotation.y += rotation;

	this->transform();
}

void GameObject::rotateZ(float rotation) {
	this->rotation.z += rotation;

	this->transform();
}
