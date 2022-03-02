#ifndef SCENE_CLASS_H
#define SCENE_CLASS_H
#include <iostream>
#include <vector>
#include "Camera.h"

#include "GameObject.h"


class Scene {
private:
	std::vector<GameObject> gameObjets[10];

public:
	Scene();
	void draw(Camera &camera);
	void update();
	void addGameObject(GameObject& obj, unsigned int layer);
};

#endif

