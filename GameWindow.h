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
			
			unsigned long timeBetweenFrame;


			Camera camera;
			std::thread thread;
		public:
			unsigned int width, height, currentFps, maxFps;
			GameWindow(unsigned int _width, unsigned _height, Scene _scene);
			Scene currentScene;
			void createWindow();
			bool isRunning, isStart;
			GLFWwindow* glfwwindow;
	};
}
#endif