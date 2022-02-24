#include "Scene.h"



void Scene::draw() {
	for(int layer=9;layer>0;layer--)
		for (GameObject& obj : gameObjets[layer]) {
			//obj.render();
		}
		
	
}

void Scene::update() {
	for (int layer = 0; layer < 10; layer++)
		for (GameObject& obj : gameObjets[layer]) {
			//update
		}
		
}

void Scene::addGameObject(GameObject obj, unsigned int layer) {
	gameObjets[layer].push_back(obj);
}