#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>
namespace fs = std::filesystem;

#include "GameObject.h"
#include "Event.h"
#include "GameWindow.h"


int main() {
	std::string parent = (fs::current_path()).string();
	GameWindow window = GameWindow(800,800,Scene());
	std::cout << window.isRunning;
	GameObject fella(glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), (parent+"/roblox.png").c_str());
	GameObject fella2(glm::vec2(0.0f, 2.0f), glm::vec2(1.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), (parent + "/roblox.png").c_str());
	printf("hello");
	window.currentScene.addGameObject(fella,1);
	window.currentScene.addGameObject(fella2, 1);
	std::cout << "Hello World!";
	/*const unsigned int WIN_HEIGHT(800);
	const unsigned int WIN_WIDTH(800);
	const float MIN_DRAW_DISTANCE(1.0f);
	const float MAX_DRAW_DISTANCE(100.0f);
=======
	/*const unsigned int WIN_HEIGHT(800);
	const unsigned int WIN_HEIGHT(800);
	const unsigned int WIN_WIDTH(800);
	const float MIN_DRAW_DISTANCE(1.0f);
	const float MAX_DRAW_DISTANCE(100.0f);
	
	*/

	//GameObject fella(glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), path.c_str());
	printf("hello");
	//window.currentScene.addGameObject(fella, 1);

	/*
	std::string parentDir = (fs::current_path()).string();
>>>>>>> Stashed changes

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window(glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "GOAT_ENGINE", NULL, NULL));

	if(window == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

	GameObject plank(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), "planks.png");
	GameObject fella(glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), "character.png");
	Camera camera(WIN_WIDTH, WIN_HEIGHT, glm::vec3(0.0f, 0.0f, 5.0f));

	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);

	Event e(window);

	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//camera.Inputs(window);
		camera.updateMatrix(60.0f, MIN_DRAW_DISTANCE, MAX_DRAW_DISTANCE);

		e.onPress(GLFW_KEY_A, fella, [](GameObject& g) {
			g.translate(glm::vec2(-1.0f, 0.0f));
		});

		e.onPress(GLFW_KEY_D, fella, [](GameObject& g) {
			g.translate(glm::vec2(1.0f, 0.0f));
		});

		e.onPress(GLFW_KEY_W, fella, [](GameObject& g) {
			g.translate(glm::vec2(0.0f, 1.0f));
		});

		e.onPress(GLFW_KEY_S, fella, [](GameObject& g) {
			g.translate(glm::vec2(0.0f, -1.0f));
		});

		e.onMouseClick(GLFW_MOUSE_BUTTON_LEFT, fella, [](GameObject& g) {
			g.rotateX(0.1f);
		});
		
		fella.render(camera);
		plank.render(camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
<<<<<<< Updated upstream

	return 0;*/

	return 0;
}

void startWindow() {

}
