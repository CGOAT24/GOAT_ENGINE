#ifndef ENNEMY_CLASS_H
#define ENNEMY_CLASS_H

#include "GameObject.h"

const char UP = 'u';
const char DOWN = 'd';
const char LEFT = 'l';
const char RIGHT = 'r';

class Ennemy : public GOAT_ENGINE::GameObject {
private:
	char direction;
	bool canBeEaten;

public:
	Ennemy();
	char getDirection() const;
	void updateCanBeEaten(bool eaten);
	void updateDirection(char newDir);
};
#endif