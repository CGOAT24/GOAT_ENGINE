#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include "GameObject.h"

const char UP = 'u';
const char DOWN = 'd';
const char LEFT = 'l';
const char RIGHT = 'r';

class Player : public GOAT_ENGINE::GameObject {
private:
	GOAT_ENGINE::Texture textures[4];
	char direction;
	
public:
	Player();
	void updateDirection(char newDir);
	char getDirection() const;
};

#endif