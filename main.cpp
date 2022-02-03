#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"

#include "Color.h"


int main() {
	const unsigned int WIN_HEIGHT = 800;
	const unsigned int WIN_WIDTH = 800;
	const float MIN_DRAW_DISTANCE = 1.0f;
	const float MAX_DRAW_DISTANCE = 100.0f;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat vertices[] =
	{	//Coordinates			//Colors				//TexCoord
		-0.5f, 0.0f, 0.5f,		0.83f, 0.7f, 0.44f,		0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.83f, 0.7f, 0.44f,		5.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		0.83f, 0.7f, 0.44f,		0.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		0.83f, 0.7f, 0.44f,		5.0f, 0.0f,
		0.0f, 0.8f, 0.0f,		0.92f, 0.86f, 0.76f,	2.5f, 5.0f
	};

	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};

	GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "GOAT_ENGINE", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

	//Generate Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	//Generate VertexArray Object and binds it
	VAO VAO1;
	VAO1.Bind();

	//Generate Vertex Buffer Object and link it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	//Generate Element Buffer Object and link it to indices
	EBO EBO1(indices, sizeof(indices));

	//Link VBO to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//Unbind every object
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	Texture img("suit.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

	img.texUnit(shaderProgram, "tex0", 0);

	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);

	Camera camera(WIN_WIDTH, WIN_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shaderProgram.Activate();

		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		img.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	img.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}