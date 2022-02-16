#include "Mesh.h"
#include "Functions.h"

int main() {
	const unsigned int WIN_HEIGHT = 800;
	const unsigned int WIN_WIDTH = 800;
	const float MIN_DRAW_DISTANCE = 1.0f;
	const float MAX_DRAW_DISTANCE = 100.0f;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	Vertex vertices[] =
	{
		//Position								//Normal						//Color							//Texture Coordinates
		Vertex{glm::vec3(-1.0f, 1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(1.0f, 0.0f)}
	};

	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	Vertex lightVertices[] = 
	{
		//Position								//Normal						//Color							//Texture Coorddinates
		Vertex{glm::vec3(-1.0f, 1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, 0.0f),	glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 1.0f, 0.0f),		glm::vec3(0.0f, 0.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 0.0f),	glm::vec2(1.0f, 0.0f)}
	};

	GLuint lightIndices[] =
	{
		0, 1, 2,
		0, 2, 3
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

	Texture textures[] = {
		Texture("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	Shader shaderProgram("default.vert", "default.frag");
	
	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	Mesh floor(verts, ind, tex);

	Shader lightShader("light.vert", "light.frag");

	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	Mesh light(lightVerts, lightInd, tex);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);


	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	glfwSwapBuffers(window);
	glEnable(GL_DEPTH_TEST);

	Camera camera(WIN_WIDTH, WIN_HEIGHT, glm::vec3(0.0f, 0.0f, 5.0f));

	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window);
		camera.updateMatrix(90.0f, MIN_DRAW_DISTANCE, MAX_DRAW_DISTANCE);

		floor.Draw(shaderProgram, camera);
		light.Draw(shaderProgram, camera);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	shaderProgram.Delete();
	lightShader.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}