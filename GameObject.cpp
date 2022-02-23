#include "GameObject.h"

GameObject::GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec2 _rotation, const char* _texName): position(_position), scale(_scale), rotation(_rotation), texture(_texName, "diffuse", 0, GL_UNSIGNED_BYTE), mesh(), shader("default.vert", "default.frag"), light() {
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
		glm::vec3 color(1.0f, 1.0f, 1.0f);

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

void GameObject::render(Camera& camera) {
	this->mesh.Draw(this->shader, camera);
}

GameObject::~GameObject() {
	this->shader.Delete();
	this->light.shader.Delete();
	delete this;
}

void GameObject::translate(glm::mat4 mat) {

}

void GameObject::setScale(glm::vec2 scaleMult) {
}

void GameObject::rotate(glm::vec2 rotation) {
}
