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

int main() {
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

	const std::string audioPath((std::filesystem::current_path().string() + "\\Audio\\").c_str());

	/*****************************************************************************************************************************													
	*												TEXTURES																	 *
	*****************************************************************************************************************************/

	const std::string texPath((std::filesystem::current_path().string() + "\\textures\\").c_str());
	const std::string POINTS_TEXTURE_NAME((texPath + "other\\pacgum.png").c_str());
	const std::string WALLS_TEXTURE_NAME((texPath + "other\\wall.png").c_str());
	
	Texture pacmanTexs[4][2] = {
		{ Texture((texPath + "pacman\\pacman_1_up.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_up.png").c_str())    },
		{ Texture((texPath + "pacman\\pacman_1_down.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_down.png").c_str())  },
		{ Texture((texPath + "pacman\\pacman_1_left.png").c_str()),	 Texture((texPath + "pacman\\pacman_2_left.png").c_str())  },
		{ Texture((texPath + "pacman\\pacman_1_right.png").c_str()), Texture((texPath + "pacman\\pacman_2_right.png").c_str()) }
	};

	/***************************************************************************************************************************
	*														GAMEOBJECTS														   *
	***************************************************************************************************************************/

	const glm::vec3 ROTATION(0.0f, 0.0f, 0.0f);
	const glm::vec2 POINTS_SIZE(0.5f, 0.5f);

	Player pacman(pacmanTexs);

	GameObject pacgums[] {
		GameObject(glm::vec2(0.0f, 2.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-2.0f, 2.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(0.0f, -1.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-2.0f, 0.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(2.0f, 0.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-4.0f, 1.0f),POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-2.0f, 1.0f),POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(0.0f, 1.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(2.0f, 1.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(4.0f, 1.0f), POINTS_SIZE, ROTATION, POINTS_TEXTURE_NAME.c_str(), true)
	};

	bool isActive[10];
	for (int i(0); i < 10; i++) {
		isActive[i] = true;
	}

	GameObject walls[] {
		GameObject(glm::vec2(0.0f, -5.0f), glm::vec2(10.0f, 0.5f), ROTATION, WALLS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(5.0f, 0.0f), glm::vec2(0.5f, 10.0f), ROTATION, WALLS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(-5.0f, 0.0f), glm::vec2(0.5f, 10.0f),ROTATION, WALLS_TEXTURE_NAME.c_str(), true),
		GameObject(glm::vec2(0.0f, 5.0f), glm::vec2(10.0f, 0.5f), ROTATION, WALLS_TEXTURE_NAME.c_str(), true)
	};

	/**************************************************************************************************************************
	*															GAME														  *
	**************************************************************************************************************************/

	Camera cam(800, 800, glm::vec3(0.0f, 0.0f, 5.0f));
	Sound soundManager = Sound();
	Event eventHandler(window);
	const float speed(50.0f);
	int pacgumsRemaining(sizeof(isActive) / sizeof(isActive[0]));

	soundManager.play((audioPath + "theme_song.mp3").c_str(), 0.5f, true);

	while (!glfwWindowShouldClose(window) && pacgumsRemaining > 0) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		cam.updateMatrix(90.0f, 0.1f, 15.0f);
		if (eventHandler.isPressed(GLFW_KEY_W)) {
			if(pacman.getPosition().y < 5.75f)
				pacman.translate(glm::vec2(0.0f, 1.0f * speed));
			pacman.updateDirection('u');
		}
		else if(eventHandler.isPressed(GLFW_KEY_S)) {
			if(pacman.getPosition().y > -5.75f)
				pacman.translate(glm::vec2(0.0f, -1.0f * speed));
			pacman.updateDirection('d');
		}
		else if (eventHandler.isPressed(GLFW_KEY_A)) {
			if(pacman.getPosition().x > -5.75f)
				pacman.translate(glm::vec2(-1.0f * speed, 0.0f));
			pacman.updateDirection('l');
		}
		else if (eventHandler.isPressed(GLFW_KEY_D)) {
			if(pacman.getPosition().x < 5.75f)
				pacman.translate(glm::vec2(1.0f * speed, 0.0f));
			pacman.updateDirection('r');
		}

		pacman.render(cam);

		for (int i(0); i < sizeof(pacgums) / sizeof(pacgums[0]); i++) {
			if (pacman.collider.isColliding(pacgums[i].collider)) {
				isActive[i] = false;
				pacgums[i].collider.setActive(false);
				soundManager.play((audioPath + "eat_gum.wav").c_str(), 0.5f, false);
			}
			
			if (isActive[i]) {
				pacgums[i].render(cam);
			}
		}

		pacgumsRemaining = 0;
		for (int i(0); i < sizeof(isActive) / sizeof(isActive[0]); i++) {
			pacgumsRemaining = isActive[i] ? ++pacgumsRemaining : pacgumsRemaining;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}