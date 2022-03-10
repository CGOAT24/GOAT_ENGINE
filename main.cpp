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

	GOAT_ENGINE::GameObject fella(
		glm::vec2(0.0f, 0.0f), 
		glm::vec2(1.0f, 1.0f), 
		glm::vec3(0.0f, 0.0f, 0.0f), 
		"character.png", 
		true
	);
	GOAT_ENGINE::GameObject plank(
		glm::vec2(1.0f, 1.0f),
		glm::vec2(1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		"planks.png",
		true
	);

	GOAT_ENGINE::Camera camera(GOAT_ENGINE::WIN_WIDTH, GOAT_ENGINE::WIN_HEIGHT, glm::vec3(0.0f, 0.0f, GOAT_ENGINE::CAM_DISTANCE));

	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);

	GOAT_ENGINE::Event e(window);
	

	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//camera.Inputs(window);
		camera.updateMatrix(90.0f, GOAT_ENGINE::MIN_DRAW_DISTANCE, GOAT_ENGINE::MAX_DRAW_DISTANCE);

		fella.render(camera);
		plank.render(camera);

		e.onPress(GLFW_KEY_W, fella, [](GOAT_ENGINE::GameObject& g) {
			g.translate(glm::vec2(0.0f, 1.0f));
		});

		e.onPress(GLFW_KEY_S, fella, [](GOAT_ENGINE::GameObject& g) {
			g.translate(glm::vec2(0.0f, -1.0f));
		});

		e.onPress(GLFW_KEY_A, fella, [](GOAT_ENGINE::GameObject& g) {
			g.translate(glm::vec2(-1.0f, 0.0f));
		});

		e.onPress(GLFW_KEY_D, fella, [](GOAT_ENGINE::GameObject& g) {
			g.translate(glm::vec2(1.0f, 0.0f));
		});

		std::cout << std::to_string(plank.getPosition().x) << std::endl;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}