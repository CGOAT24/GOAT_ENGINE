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
	timeBetweenFrame = 1000000 / maxFps;
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

	auto lastFpsUpdate = std::chrono::high_resolution_clock::now();

	unsigned int frame = 0;
	long renderTime = 0;

	while (!glfwWindowShouldClose(window)) {
		auto startFrame = std::chrono::high_resolution_clock::now();

		glfwPollEvents();
		
		update();
		draw();
		frame++;

		auto elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;

		if (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() >= 1000000) {
			currentFps = frame;
			frame = 0;
			lastFpsUpdate = std::chrono::high_resolution_clock::now();
			cout << currentFps << " fps"<<std::endl;
			elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;
		}
		unsigned long nextFrame;
		if (frame >= maxFps) {
			nextFrame = (1000000 - (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()));
		}
		else {
			auto elapsedFrame = std::chrono::high_resolution_clock::now() - startFrame;
			/*long frameLenght = std::chrono::duration_cast<std::chrono::microseconds>(elapsedFrame).count();
			if ((((1000000 - (frameLenght * (maxFps - frame))) - (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()))) < 0) {
				frameLenght = (((1000000 - (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()))) / (maxFps - frame));
			}*/
			nextFrame = (((1000000)-(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count())))/(maxFps-frame);
			//cout << nextFrame << endl;
		}
		
		std::this_thread::sleep_for(std::chrono::microseconds(nextFrame));
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void GameWindow::update() {

}

void GameWindow::draw() {

}