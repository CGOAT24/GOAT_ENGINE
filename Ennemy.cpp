#include "Ennemy.h"

Ennemy::Ennemy(glm::vec2 position, GOAT_ENGINE::Texture _textures[4]): GameObject(position, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), (std::filesystem::current_path().string() + "\\textures\\default.png").c_str(), true), direction(0), canBeEaten(false) {
	for (int i(0); i < 4; i++) {
		this->textures[i] = _textures[i];
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
		this->mesh.texture = this->getTexture();
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

GOAT_ENGINE::Texture Ennemy::getTexture() {
	return this->textures[direction];
}