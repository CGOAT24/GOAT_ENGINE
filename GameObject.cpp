#include "GameObject.h"
#include "Functions.h"

GameObject::GameObject(glm::vec2 _position, glm::vec2 _size, glm::vec2 _rotation, Texture _textures[2]) : position(_position), size(_size), rotation(_rotation), textures(_textures) {
	Vertex vertices[4];
	
	std::vector<glm::vec2> vertPos = 
	{				
		glm::vec2(_position.x - (size.x / 2), _position.y - (size.y / 2)),	//bottom left
		glm::vec2(_position.x + (size.x / 2), _position.y - (size.y / 2)),	//bottom right
		glm::vec2(_position.x + (size.x / 2), _position.y + (size.y / 2)),	//top right
		glm::vec2(_position.x - (size.x / 2), _position.y + (size.y / 2))	//top left
	};

	std::vector<glm::vec2> texCoords =
	{
		glm::vec2(0.0f, 0.0f),												//bottom left
		glm::vec2(1.0f, 0.0f),												//bottom right
		glm::vec2(1.0f, 1.0f),												//top right
		glm::vec2(0.0f, 1.0f)												//top left
	};
	
	v2ToVertex(vertPos, texCoords, vertices);

	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> tex(_textures, _textures + sizeof(_textures) / sizeof(Texture));

	mesh = Mesh(verts, ind, tex);
}
