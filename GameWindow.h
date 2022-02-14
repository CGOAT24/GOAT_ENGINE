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

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"

class GameWindow
{
private:
	unsigned int width, height, currentFps, maxFps;
	unsigned long timeBetweenFrame;
public:
	
	GameWindow(unsigned int _width, unsigned _height);

	int createWindow();

	void update();
	
	void draw();
};

#endif

