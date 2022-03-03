#include "GameWindow.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

GameWindow::GameWindow(unsigned int _width, unsigned _height, Scene _scene) : width(_width), height(_height), currentFps(0), maxFps(60), timeBetweenFrame(1000000 / maxFps), currentScene(_scene), camera(Camera(width, height, glm::vec3(0.0f, 0.0f, 5.0f))) {
	isRunning = true;
	thread = std::thread(&GameWindow::createWindow,this);
	isStart = false;
	while(isStart)
		std::this_thread::sleep_for(std::chrono::microseconds(100));
}

/// <summary>
/// Créer la fenêtre et démarer le jeux
/// </summary>
/// <returns>Code de réponse</returns>
void GameWindow::createWindow() {
	//Créer la fenêtre
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwwindow = glfwCreateWindow(width, height, "GOAT_ENGINE", NULL, NULL);
	//Si erreur durant la création de la fenêtre
	if (glfwwindow == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(glfwwindow);

	gladLoadGL();
	glViewport(0, 0, width, height);
	
	//GameLoop
	auto lastFpsUpdate = std::chrono::high_resolution_clock::now();

	unsigned int frame = 0;
	isStart = true;
	while (!glfwWindowShouldClose(glfwwindow)) {
		auto startFrame = std::chrono::high_resolution_clock::now();

		glfwPollEvents();
		
		camera.updateMatrix(60.0f, 1.0f, 100.0f);
		//Update et render la scène
		currentScene.update();
		currentScene.draw();

		frame++;

		auto elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;

		if (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() >= 1000000) {
			currentFps = frame;
			frame = 0;
			lastFpsUpdate = std::chrono::high_resolution_clock::now();
			cout << currentFps << " fps" << std::endl;
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

	glfwDestroyWindow(glfwwindow);
	glfwTerminate();
	isRunning = false;
	return;
}
