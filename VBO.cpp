#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
	glGenBuffers(1, &this->ID);
	glBindBuffer(GL_ARRAY_BUFFER, this->ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
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
