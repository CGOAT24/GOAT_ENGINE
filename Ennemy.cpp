#include "Ennemy.h"

Ennemy::Ennemy(glm::vec2 position, char _color, GOAT_ENGINE::Texture _textures[4][2]): GameObject(position, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), (std::filesystem::current_path().string() + "\\textures\\default.png").c_str(), true), direction(0), canBeEaten(false), color(_color) {
	for (int i(0); i < 4; i++) {
		for (int j(0); j < 2; j++) {
			this->textures[i][j] = _textures[i][j];
		}
	}
}

char Ennemy::getDirection() const {
	return this->direction;
}

void Ennemy::updateCanBeEaten(bool eaten) {
	this->canBeEaten = eaten;
	
	if (canBeEaten) {
		this->mesh.texture = GOAT_ENGINE::Texture((std::filesystem::current_path().string() + "\\textures\\ennemies\\dead.png").c_str());
	}
	else {
		this->mesh.texture = GOAT_ENGINE::Texture((this->getTexPath()).c_str());
	}
}

/***************
* UP	---> 0 *
* DOWN  ---> 1 *
* LEFT  ---> 2 *
* RIGHT ---> 3 *
***************/
void Ennemy::move() {
	switch (this->direction) {
	case 0:	//up
		this->translate(glm::vec2(0.0f, 1.0f)); 
		break;
	case 1:	//down
		this->translate(glm::vec2(0.0f, -1.0f));
		break;
	case 2:	//left
		this->translate(glm::vec2(-1.0f, 0.0f));
		break;
	case 3:	//right
		this->translate(glm::vec2(1.0f, 0.0f));
		break;
	}
}

std::string Ennemy::getTexPath() {
	const std::string path((std::filesystem::current_path().string() + "\\textures\\ennemies\\").c_str());
	std::string texName = "";

	switch (color) {
	case 'c':
		texName += "cyan_";
		break;
	case 'o':
		texName += "orange_";
		break;
	case 'p':
		texName += "pink_";
		break;
	case 'r':
		texName += "red_";
		break;
	}

	switch (direction) {
	case 0:
		texName += "up.png";
		break;
	case 1:
		texName += "down.png";
		break;
	case 2:
		texName += "left.png";
		break;
	case 3:
		texName += "right.png";
		break;
	}

	return path + texName;
}