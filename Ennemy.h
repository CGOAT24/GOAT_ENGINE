#ifndef ENNEMY_CLASS_H
#define ENNEMY_CLASS_H

#include "GameObject.h"

class Ennemy : public GOAT_ENGINE::GameObject {
private:
	GOAT_ENGINE::Texture textures[4];
	int direction;
	bool canBeEaten;
	char color;

	std::string getTexPath();

public:
	Ennemy(glm::vec2 position, char color, GOAT_ENGINE::Texture _textures[4]);
	char getDirection() const;
	void updateCanBeEaten(bool eaten);
	void move();
};
#endif