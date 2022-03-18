#include "Texture.h"

GOAT_ENGINE::Texture::Texture(const char* image, const char* texType, GLuint slot, GLenum pixelType) {
	GLenum format;
	int widthImg, heightImg, numColCh;
	type = texType;
	unit = slot;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	if (stbi_failure_reason()) {
		throw std::exception(stbi_failure_reason());
	}

	switch (numColCh) {
	case 1:
		format = GL_RED;
		break;
	case 3:
		format = GL_RGB;
		break;
	case 4:
		format = GL_RGBA;
		break;
	default:
		throw std::invalid_argument("le type de texture n'a pas pu être reconnu");	//Message d'erreur à revoir
		break;
	}

	glGenTextures(1, &ID);


	glActiveTexture(GL_TEXTURE + slot);

	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);
}

GOAT_ENGINE::Texture::Texture(const char* texPath) {
	GLenum format;
	int widthImg, heightImg, numColCh;
	type = "diffuse";
	unit = 0;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(texPath, &widthImg, &heightImg, &numColCh, 0);

	if (stbi_failure_reason()) {
		throw std::exception(stbi_failure_reason());
	}

	switch (numColCh) {
	case 1:
		format = GL_RED;
		break;
	case 3:
		format = GL_RGB;
		break;
	case 4:
		format = GL_RGBA;
		break;
	default:
		throw std::invalid_argument("le type de texture n'a pas pu être reconnu");	//Message d'erreur à revoir
		break;
	}

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE + 0);

	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, GL_UNSIGNED_BYTE, bytes);

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void GOAT_ENGINE::Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void GOAT_ENGINE::Texture::Bind() {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void GOAT_ENGINE::Texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void GOAT_ENGINE::Texture::Delete() {
	glDeleteTextures(1, &ID);
}