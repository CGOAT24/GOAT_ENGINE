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
#include "Sound.h"

using namespace GOAT_ENGINE;

GLFWwindow* initGLFW();

int main() {

	GLFWwindow* window = initGLFW();

	/*****************************************************************************************************************************													
	*												TEXTURES																	 *
	*****************************************************************************************************************************/
	const std::string texPath((std::filesystem::current_path().string() + "\\textures\\").c_str());
	const std::string POINTS_TEXTURE_NAME((texPath + "other\\pacgum.png").c_str());
	
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
		Texture((texPath + "ennemies\\red_up.png").c_str()),
		Texture((texPath + "ennemies\\red_down.png").c_str()),
		Texture((texPath + "ennemies\\red_left.png").c_str()),
		Texture((texPath + "ennemies\\red_right.png").c_str())
	};

	/***************************************************************************************************************************
	*														GAMEOBJECTS														   *
	***************************************************************************************************************************/

	Ennemy ennemies[4] = {
		Ennemy(glm::vec2(-1.0f, 1.0f), redTexs),
		Ennemy(glm::vec2(1.0f, 1.0f), pinkTexs),
		Ennemy(glm::vec2(1.0f, -1.0f), orangeTexs),
		Ennemy(glm::vec2(-1.0f, -1.0f), cyanTexs)
	};

	const glm::vec2 POINTS_SIZE(0.5f, 0.5f); //à vérifier
	const glm::vec3 POINTS_ROTATION(0.0f, 0.0f, 0.0f);
	
	
	std::vector<GameObject> pacgums {
		GameObject(glm::vec2(0.0f, 2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-2.0f, 2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-4.0f, 2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-4.0f, 0.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-4.0f, -2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-2.0f, -2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(0.0f, -2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(2.0f, -2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(4.0f, -2.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(4.0f, 0.0f), POINTS_SIZE, POINTS_ROTATION, POINTS_TEXTURE_NAME.c_str(), true)
	};

	/*
	GameObject* walls = {
	
	};
	*/

	GameObject cherry(glm::vec2(2.0f, 2.0f), glm::vec2(0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), (texPath + "other\\cherry.png").c_str(), true);
	Player pacman(pacmanTexs);

	/**************************************************************************************************************************
	*															GAME														  *
	**************************************************************************************************************************/

	Camera cam(800, 800, glm::vec3(0.0f, 0.0f, 5.0f));
	Event eventHandler(window);

	Shader lightShader("light.vert", "light.frag");
	Light light(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cam.updateMatrix(90.0f, 0.1f, 10.0f);

		//Gestion des déplacements
		if (eventHandler.isPressed(GLFW_KEY_W)) {
			if(pacman.getPosition().y < 6.0f)
				pacman.translate(glm::vec2(0.0f, 1.0f));
			pacman.updateDirection('u');
		}
		else if(eventHandler.isPressed(GLFW_KEY_S)) {
			if(pacman.getPosition().y > -6.0f)
				pacman.translate(glm::vec2(0.0f, -1.0f));
			pacman.updateDirection('d');
		}
		else if (eventHandler.isPressed(GLFW_KEY_A)) {
			if(pacman.getPosition().x > -6.0f)
				pacman.translate(glm::vec2(-1.0f, 0.0f));
			pacman.updateDirection('l');
		}
		else if (eventHandler.isPressed(GLFW_KEY_D)) {
			if (pacman.getPosition().x < 6.0f)
				pacman.translate(glm::vec2(1.0f, 0.0f));
			pacman.updateDirection('r');
		}

		light.Activate(lightShader);

		pacman.render(cam);

		//Gestion des pacgums
		for (int i(0); i < pacgums.size(); i++) {
			/*
			if (pacgums.at(i).collider.isColliding(pacman.collider)) {
				pacgums.erase(pacgums.begin() + i);
			}
			*/

			pacgums.at(i).render(cam);
		}

		cherry.render(cam);

		//Gestion des ennemies
		for (int i(0); i < (sizeof(ennemies) / sizeof(ennemies[0])); i++) {
			if (ennemies[i].getIsActive()) {
				//ennemies[i].move();

				/*
				bool ennemyCollides(false);
				for (int i(0); i < (sizeof(walls) / sizeof(walls[0])); i++) {

					if (ennemies[i].collider.isColliding(walls[i].collider)) {
						ennemyCollides = true;
						break;
					}
				}

				if (ennemyCollides) {
					ennemies[i].cancelMove();
					ennemies[i].updateDirection();
				}
				*/

				ennemies[i].render(cam);
			}
		}

		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

GLFWwindow* initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window(glfwCreateWindow(800, 800, "GOAT_ENGINE", NULL, NULL));

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);
	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);

	return window;
}