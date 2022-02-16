#ifndef SCENE_CLASS_H
#define SCENE_CLASS_H
#include <iostream>
#include <vector>

#include "GameObject.h"


class Scene {
private:
	std::vector<GameObject> gameObjets;

public:
	Scene();
	void draw();
	void update();
};

#endif

