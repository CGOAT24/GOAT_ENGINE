#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>

#include "Values.h"
#include "GameObject.h"
#include "Event.h"
#include "GameWindow.h"

using namespace GOAT_ENGINE;

int main() {
	/*
	GameWindow window = GameWindow(800,800,Scene());
	window.currentScene.addGameObject(fella,1);
	*/
	
	std::string rootDir = (std::filesystem::current_path()).string();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window(glfwCreateWindow(GOAT_ENGINE::WIN_WIDTH, GOAT_ENGINE::WIN_HEIGHT, "GOAT_ENGINE", NULL, NULL));

	if(window == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, GOAT_ENGINE::WIN_WIDTH, GOAT_ENGINE::WIN_HEIGHT);

	GameObject fella(
		glm::vec2(0.0f, 0.0f), 
		glm::vec2(1.0f, 1.0f), 
		glm::vec3(0.0f, 0.0f, 0.0f), 
		"character.png", 
		true
	);

	GameObject plank(
		glm::vec2(1.0f, 1.0f),
		glm::vec2(1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		"planks.png",
		true
	);

	Camera cam(WIN_WIDTH, WIN_HEIGHT, glm::vec3(0.0f, 0.0f, CAM_DISTANCE));
	Event eventHandler(window);

	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);
	
	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cam.updateMatrix(CAM_FOV, MIN_DRAW_DISTANCE, MAX_DRAW_DISTANCE);

		fella.render(cam);
		plank.render(cam);

		eventHandler.onPress(GLFW_KEY_W, fella, [](GameObject& g) {
			g.translate(glm::vec2(0.0f, 2.0f));
		});

		eventHandler.onPress(GLFW_KEY_S, fella, [](GameObject& g) {
			g.translate(glm::vec2(0.0f, -2.0f));
		});

		eventHandler.onPress(GLFW_KEY_A, fella, [](GameObject& g) {
			g.translate(glm::vec2(-2.0f, 0.0f));
		});

		eventHandler.onPress(GLFW_KEY_D, fella, [](GameObject& g) {
			g.translate(glm::vec2(2.0f, 0.0f));
		});

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}