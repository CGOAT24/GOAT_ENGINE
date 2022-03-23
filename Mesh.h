#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <string>
#include <filesystem>
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"

namespace GOAT_ENGINE {
	class Mesh {
	public:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		Texture texture;

		VAO VAO;
		Mesh();
		Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Texture& textures);

		void Draw(Shader& shader, GOAT_ENGINE::Camera& camera);
	};
}
#endif