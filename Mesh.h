#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <string>
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	Texture texture;
	std::vector<Texture> textures;

	VAO VAO;
	Mesh();
	Mesh(std::vector<Vertex>& _vertices, std::vector<GLuint>& _indices, std::vector<Texture>& _textures);
	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Texture& textures);

	void Draw(Shader& shader, Camera& camera);
};
#endif