#include "Camera.h"

/// <summary>
/// Constructeur pour la classe caméra
/// </summary>
/// <param name="width">largeur de la caméra. Il est recommandé d'utilisateur la largeur de la fenêtre</param>
/// <param name="height">Hauteur de la caméra. Il est recommandé d'utilisateur la hauteur de la fenêtre</param>
/// <param name="position">Position de la caméra</param>
Camera::Camera(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

/// <summary>
///	
/// </summary>
/// <param name="FOVdeg">L'angle du champ de vision de la caméra</param>
/// <param name="nearPlane">Distance minimale où la caméra va rendre les modèles</param>
/// <param name="farPlane">Distance maximale où la caméra va rendre les modèles</param>
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