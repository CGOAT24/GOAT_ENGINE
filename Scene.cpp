#include "Scene.h"

Scene::Scene() {

}


void Scene::draw(Camera &camera) {
	
	for (int layer = 9; layer >= 0; layer--) {
		
		for (GameObject& obj : gameObjets[layer]) {
			
			obj.render(camera);
		}
	}
		
	
}

void Scene::update() {
	for (int layer = 0; layer < 10; layer++)
		for (GameObject& obj : gameObjets[layer]) {
			
		}
		
}

void Scene::addGameObject(GameObject& obj, unsigned int layer) {
	std::cout << "new obj ";
	gameObjets[layer].push_back(obj);
}