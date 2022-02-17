#include "GameObject.h"
#include "Functions.h"

GameObject::GameObject(glm::vec2 _position, glm::vec2 _scale, glm::vec2 _rotation, const Texture& _texture): position(_position), scale(_scale), rotation(_rotation), texture(_texture.image, ) {

	Vertex vertices[4];
	
	std::vector<glm::vec2> vertPos = {
		glm::vec2(_position.x - (scale.x / 2), _position.y - (scale.y / 2)),	//bottom left
		glm::vec2(_position.x + (scale.x / 2), _position.y - (scale.y / 2)),	//bottom right
		glm::vec2(_position.x + (scale.x / 2), _position.y + (scale.y / 2)),	//top right
		glm::vec2(_position.x - (scale.x / 2), _position.y + (scale.y / 2))		//top left
	};

	std::vector<glm::vec2> texCoords = {
		glm::vec2(0.0f, 0.0f),												//bottom left
		glm::vec2(1.0f, 0.0f),												//bottom right
		glm::vec2(1.0f, 1.0f),												//top right
		glm::vec2(0.0f, 1.0f)												//top left
	};
	
	v2ToVertex(vertPos, texCoords, vertices);

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	/*std::vector<Texture> tex(texture, texture + sizeof(texture) / sizeof(Texture));*/


	mesh = Mesh(verts, ind, _texture);
}
