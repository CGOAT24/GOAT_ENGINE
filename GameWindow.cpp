#include "GameWindow.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

GameWindow::GameWindow(unsigned int _width, unsigned _height) {
	
	width = _width;
	height = _height;
	currentFps = 0;
	maxFps = 60;
	timeBetweenFrame = 1000000000 / maxFps;
}

int GameWindow::createWindow() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "GOAT_ENGINE", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, width, height);

	auto nextFrame = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		auto time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}