#include "Camera.h"

/// <summary>
/// Constructeur pour la classe cam�ra
/// </summary>
/// <param name="width">largeur de la cam�ra. Il est recommand� d'utilisateur la largeur de la fen�tre</param>
/// <param name="height">Hauteur de la cam�ra. Il est recommand� d'utilisateur la hauteur de la fen�tre</param>
/// <param name="position">Position de la cam�ra</param>
Camera::Camera(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

/// <summary>
///	
/// </summary>
/// <param name="FOVdeg">L'angle du champ de vision de la cam�ra</param>
/// <param name="nearPlane">Distance minimale o� la cam�ra va rendre les mod�les</param>
/// <param name="farPlane">Distance maximale o� la cam�ra va rendre les mod�les</param>
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	cameraMatrix = projection * view;
}

/// <summary>
/// 
/// </summary>
/// <param name="shader"></param>
/// <param name="uniform"></param>
void Camera::Matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Camera::Inputs(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.04f;
	}
	else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.01f;
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		Position += speed * Up;
	}

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}

	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Position += speed * -Up;
	}

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
}