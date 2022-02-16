#include "VBO.h"

/// <summary>
/// Constructeur pour le Vertex Buffer Object
/// </summary>
/// <param name="vertices"></param>
VBO::VBO(std::vector<Vertex>& vertices) {
	glGenBuffers(1, &this->ID);
	glBindBuffer(GL_ARRAY_BUFFER, this->ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void VBO::Delete() {
	glDeleteBuffers(1, &this->ID);
}
