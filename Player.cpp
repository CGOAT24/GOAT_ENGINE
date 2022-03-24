#include "Player.h"

//Constructeur
Player::Player() {
}

/*
Updates direction member and updates Texture to corresponding direction
*/
void Player::updateDirection(char newDir) {
	if (this->direction != newDir) {
		this->direction = newDir;
		switch (this->direction) {
		case UP:	//up
			this->mesh.texture = textures[0];	//� v�rifier
			break;
		case DOWN:	//down
			this->mesh.texture = textures[1];	//� v�rifier
			break;
		case LEFT:	//left
			this->mesh.texture = textures[2];	//� v�rifier
			break;
		case RIGHT:	//right
			this->mesh.texture = textures[3];	//� v�rifier
			break;
		}
	}
}

/*
Getter for player's direction

UP		--->	'u'
DOWN	--->	'd'
LEFT	--->	'l'
RIGHT	--->	'r'
*/
char Player::getDirection() const {
	return this->direction;
}
