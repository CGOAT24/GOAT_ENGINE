#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>

#include "Player.h"
#include "Ennemy.h"
#include "Event.h"
#include "GameWindow.h"
#include "Sound.h"

using namespace GOAT_ENGINE;

int main() {
	const std::string texPath((std::filesystem::current_path().string() + "\\textures\\").c_str());
	Scene mainScene = Scene();
	GameWindow window(1000, 1000);
	
	Texture pacmanTexs[4][2] = {
		{ Texture((texPath + "pacman\\pacman_1_up.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_up.png").c_str())    },
		{ Texture((texPath + "pacman\\pacman_1_down.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_down.png").c_str())  },
		{ Texture((texPath + "pacman\\pacman_1_left.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_left.png").c_str())  },
		{ Texture((texPath + "pacman\\pacman_1_right.png").c_str()), Texture((texPath + "pacman\\pacman_2_right.png").c_str()) }
	};

	Texture cyanTexs[4] = {
		Texture((texPath + "ennemies\\cyan_up.png").c_str()),
		Texture((texPath + "ennemies\\cyan_down.png").c_str()),
		Texture((texPath + "ennemies\\cyan_left.png").c_str()),
		Texture((texPath + "ennemies\\cyan_right.png").c_str())
	};

	Texture orangeTexs[4] = {
		Texture((texPath + "ennemies\\orange_up.png").c_str()),
		Texture((texPath + "ennemies\\orange_down.png").c_str()),
		Texture((texPath + "ennemies\\orange_left.png").c_str()),
		Texture((texPath + "ennemies\\orange_right.png").c_str())
	};

	Texture pinkTexs[4] = {
		Texture((texPath + "ennemies\\pink_up.png").c_str()),
		Texture((texPath + "ennemies\\pink_down.png").c_str()),
		Texture((texPath + "ennemies\\pink_left.png").c_str()),
		Texture((texPath + "ennemies\\pink_right.png").c_str())
	};

	Texture redTexs[4] = {
		Texture((texPath + "ennemies\\pink_up.png").c_str()),
		Texture((texPath + "ennemies\\pink_down.png").c_str()),
		Texture((texPath + "ennemies\\pink_left.png").c_str()),
		Texture((texPath + "ennemies\\pink_right.png").c_str())
	};

	Ennemy red(glm::vec2(-1.0f, 1.0f), 'r', redTexs);
	Ennemy pink(glm::vec2(1.0f, 1.0f), 'p', pinkTexs);
	Ennemy orange(glm::vec2(1.0f, -1.0f), 'o', orangeTexs);
	Ennemy cyan(glm::vec2(-1.0f, -1.0f), 'c', cyanTexs);

	Player pacman(pacmanTexs);

	mainScene.addGameObject(pacman, 0);
	
	window.currentScene = mainScene;
	window.createWindow();

	return 0;
}