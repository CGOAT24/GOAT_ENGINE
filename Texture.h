#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>
#include "shaderClass.h"

namespace GOAT_ENGINE {
	class Texture {
	public:
		GLuint ID;
		const char* type;
		GLuint unit;
		const char* name;

		Texture(const char* texPath);

		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		void Bind();
		void Unbind();
		void Delete();
	};
}
#endif