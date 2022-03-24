#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>

#include "Player.h"
#include "Ennemy.h"
#include "Event.h"
#include "GameWindow.h"
#include "Sound.h"

using namespace GOAT_ENGINE;

int main() {

	GameObject player();

	Scene mainScene = Scene();
	GameWindow window(800, 800, mainScene);
	window.createWindow();

	return 0;
}