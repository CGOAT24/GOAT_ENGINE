#ifndef GAMEWINDOW_CLASS_H
#define GAMEWINDOW_CLASS_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <ctime>
#include <thread>

#include "Scene.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"
#include "GameObject.h"
namespace GOAT_ENGINE {
	class GameWindow {
		private:
			unsigned int width, height, currentFps, maxFps;
			unsigned long timeBetweenFrame;
			std::thread thread;
			Camera camera;
			
		public:
			bool isRunning, isStart;
			GLFWwindow* glfwwindow;
			Scene currentScene;

			GameWindow(unsigned int _width, unsigned int _height, Scene _scene);
			void createWindow();
	};
}
#endif