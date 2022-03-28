#include "Player.h"

//Constructeur
Player::Player(GOAT_ENGINE::Texture _textures[4][2]): GameObject(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), ((std::filesystem::current_path().string() + "\\Textures\\pacman\\pacman_1_right.png").c_str()), true), direction('r'), textures(), animCount(0) {
	for (int i(0); i < 4; i++) {
		for (int j(0); j < 2; j++) {
			this->textures[i][j] = _textures[i][j];
		}
	}
}

//Updates direction member and updates Texture to corresponding direction
void Player::updateDirection(char newDir) {
	if (this->direction != newDir) {
		this->direction = newDir;
		switch (this->direction) {
		case 'u':	//up
			this->mesh.texture = this->textures[0][0];	//à vérifier
			break;
		case 'd':	//down
			this->mesh.texture = this->textures[1][0];	//à vérifier
			break;
		case 'l':	//left
			this->mesh.texture = this->textures[2][0];	//à vérifier
			break;
		case 'r':	//right
			this->mesh.texture = this->textures[3][0];	//à vérifier
			break;
		}
	}
}

/********************************
* Getter for player's direction *
* UP	  --->	'u'				*
* DOWN  --->	'd'				*
* LEFT  --->	'l'				*
* RIGHT --->	'r'				*
********************************/
char Player::getDirection() const {
	return this->direction;
}

void Player::updateTexture(){
	const std::string path((std::filesystem::current_path().string() + "\\textures\\pacman\\").c_str());
	switch (this->direction) {
	case 'u':
		this->mesh.texture = this->animCount == 0 ? GOAT_ENGINE::Texture((path + "pacman_2_up.png").c_str()) : GOAT_ENGINE::Texture((path + "pacman_1_up.png").c_str());
		break;
	case 'd':
		this->mesh.texture = this->animCount == 0 ? GOAT_ENGINE::Texture((path + "pacman_2_down.png").c_str()) : GOAT_ENGINE::Texture((path + "pacman_1_down.png").c_str());
		break;
	case 'l':
		this->mesh.texture = this->animCount == 0 ? GOAT_ENGINE::Texture((path + "pacman_2_left.png").c_str()) : GOAT_ENGINE::Texture((path + "pacman_1_left.png").c_str());
		break;
	case 'r':
		this->mesh.texture = this->animCount == 0 ? GOAT_ENGINE::Texture((path + "pacman_2_right.png").c_str()) : GOAT_ENGINE::Texture((path + "pacman_1_right.png").c_str());
		break;
	}
}
