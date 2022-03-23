#include "Scene.h"

GOAT_ENGINE::Scene::Scene() {
}


void GOAT_ENGINE::Scene::draw(Camera &camera) {
	for (int layer = 9; layer >= 0; layer--) {
		for (GameObject& obj : gameObjets[layer]) {
			obj.render(camera);
		}
	}
}

void GOAT_ENGINE::Scene::update() {
	for (int layer = 0; layer < 10; layer++) {
		for (GameObject& obj : gameObjets[layer]) {

		}
	}
}

void GOAT_ENGINE::Scene::addGameObject(GameObject& obj, unsigned int layer) {
	gameObjets[layer].push_back(obj);
}