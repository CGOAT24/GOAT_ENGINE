#include "Functions.h"

/// <summary>
/// Sert à convertir une liste de vecteur2D en une liste de Vertex
/// </summary>
/// <param name="pos">une liste de points de type vecteur2D</param>
/// <param name="texCoord">les coordonées de la textures</param>
/// <returns>Liste de vertex</returns>
std::vector<Vertex> v2ToVertex(std::vector<glm::vec2> pos, std::vector<glm::vec2> texCoord) {
	std::vector<Vertex> vertices = std::vector<Vertex>();

	for(int i = 0; i < pos.size(); i++) {
		glm::vec3 position(pos.at(i).x, pos.at(i).y, 0.0f);
		glm::vec3 normal(0.0f, 0.0f, 1.0f);
		glm::vec3 color(1.0f, 1.0f, 1.0f);
		
		Vertex vi{position, normal, color, texCoord.at(i)};
		vertices.push_back(vi);
	}

	return vertices;
}
