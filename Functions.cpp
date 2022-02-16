#include "Functions.h"

/// <summary>
/// 
/// </summary>
/// <param name="pos"></param>
/// <param name="texCoord"></param>
/// <param name="output"></param>
void v2ToVertex(std::vector<glm::vec2> pos, std::vector<glm::vec2> texCoord, Vertex (&output)[4]) {

	for(int i = 0; i < pos.size(); i++) {
		glm::vec3 position(pos.at(i).x, pos.at(i).y, 0.0f);
		glm::vec3 normal(0.0f, 0.0f, 1.0f);
		glm::vec3 color(1.0f, 1.0f, 1.0f);
		
		Vertex vi{position, normal, color, texCoord.at(i)};
		output[i] = vi;
	}
}
