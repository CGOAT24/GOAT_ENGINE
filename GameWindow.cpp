#include "GameWindow.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

GOAT_ENGINE::GameWindow::GameWindow(unsigned int _width, unsigned _height, Scene _scene) : width(_width), height(_height), currentFps(0), maxFps(60), timeBetweenFrame(1000000 / maxFps), currentScene(_scene), camera(Camera(width, height, glm::vec3(0.0f, 0.0f, 5.0f))) {
	isRunning = true;
	isStart = true;
	createWindow();
}

/// <summary>
/// Cr�er la fen�tre et d�marer le jeux
/// </summary>
/// <returns>Code de r�ponse</returns>
void GOAT_ENGINE::GameWindow::createWindow() {
	//Cr�er la fen�tre
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwwindow = glfwCreateWindow(width, height, "GOAT_ENGINE", NULL, NULL);
	//Si erreur durant la cr�ation de la fen�tre
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
	GameObject fella(glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), "background.jpeg");
	currentScene.addGameObject(fella,1);
	long timeFrame = 1000000 / 60;
	while (!glfwWindowShouldClose(glfwwindow)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		auto startFrame = std::chrono::high_resolution_clock::now();

		
		camera.Inputs(glfwwindow);
		camera.updateMatrix(60.0f, 1.0f, 100.0f);
		
		//Update et render la sc�ne
		currentScene.update();
		currentScene.draw(this->camera);

		frame++;

		auto elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;

		if (std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() >= 1000000) {
			currentFps = frame;
			lastFpsUpdate = std::chrono::high_resolution_clock::now();
			cout << currentFps << " fps" << std::endl;
			elapsed = std::chrono::high_resolution_clock::now() - lastFpsUpdate;
		}

		glfwSwapBuffers(glfwwindow);
		glfwPollEvents();
		std::this_thread::sleep_for(std::chrono::microseconds(timeFrame));
	}

	glfwDestroyWindow(glfwwindow);
	glfwTerminate();
	isRunning = false;
	return;
}
