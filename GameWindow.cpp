#include "GameWindow.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

GOAT_ENGINE::GameWindow::GameWindow(unsigned int _width, unsigned int _height) : width(_width), height(_height), currentFps(0), maxFps(60), timeBetweenFrame(1000000 / maxFps), camera(Camera(width, height, glm::vec3(0.0f, 0.0f, 5.0f))), isRunning(true), isStart(true) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->glfwwindow = glfwCreateWindow(800, 800, "GOAT_ENGINE", NULL, NULL);
	glfwMakeContextCurrent(glfwwindow);
	gladLoadGL();
	glViewport(0, 0, 800, 800);
}

void GOAT_ENGINE::GameWindow::createWindow() {	
	auto lastFpsUpdate = std::chrono::high_resolution_clock::now();
	long sleepTime = 1000000 / (maxFps * 2);
	long timeFrame = 1000000 / 60;
	unsigned int frame = 0;
	isStart = true;

	while (!glfwWindowShouldClose(glfwwindow)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		auto startFrame = std::chrono::high_resolution_clock::now();

		camera.updateMatrix(60.0f, 1.0f, 100.0f);
		currentScene.update();
		currentScene.draw(this->camera);

		frame++;
		auto elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;

		if (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() >= 1000000) {
			currentFps = frame;
			lastFpsUpdate = std::chrono::high_resolution_clock::now();
			cout << currentFps << " fps" << std::endl;
			elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;
			frame = 0;
		}

		glfwSwapBuffers(glfwwindow);
		glfwPollEvents();
		
		long fluidTime = timeFrame;
		if (fluidTime > sleepTime) {
			fluidTime = sleepTime;
		}

		timeFrame = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startFrame).count();
		std::this_thread::sleep_for(std::chrono::microseconds(sleepTime-fluidTime));
	}

	glfwDestroyWindow(glfwwindow);
	glfwTerminate();
	isRunning = false;
}

void GOAT_ENGINE::GameWindow::setScene(Scene scene) {
	this->currentScene = scene;
}