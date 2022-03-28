#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "GameObject.h"

class Player : public GOAT_ENGINE::GameObject {
private:
	GOAT_ENGINE::Texture textures[4][2];
	char direction;
	int animCount;

public:
	Player(GOAT_ENGINE::Texture _textures[4][2]);
	void updateDirection(char newDir);
	char getDirection() const;
	void updateTexture();
};

#endif