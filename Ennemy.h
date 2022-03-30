#ifndef ENNEMY_CLASS_H
#define ENNEMY_CLASS_H

#include "GameObject.h"

//Classe héritée de GameObject créée par l'utilisateur 
class Ennemy : public GOAT_ENGINE::GameObject {
private:
	GOAT_ENGINE::Texture textures[4];
	int direction;
	bool canBeEaten;
	bool isActive;

	GOAT_ENGINE::Texture getTexture();

public:
	Ennemy(glm::vec2 position, GOAT_ENGINE::Texture _textures[4]);
	void move();
	void cancelMove();

	//getters
	char getDirection() const;
	bool getIsActive() const;

	//setter
	void updateCanBeEaten(bool eaten);
	void updateDirection();
	void setIsActive(bool active);
};
#endif