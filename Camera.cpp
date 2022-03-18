#include "Camera.h"

/// <summary>
/// Constructeur pour la classe cam�ra
/// </summary>
/// <param name="_width">largeur de la cam�ra</param>
/// <param name="_height">hauteur de la cam�ra</param>
/// <param name="_position">position de la cam�ra</param>
GOAT_ENGINE::Camera::Camera(int _width, int _height, glm::vec3 _position) {
	Camera::width = _width;
	Camera::height = _height;
	position = _position;
}

/// <summary>
/// 
/// </summary>
/// <param name="FOVdeg"></param>
/// <param name="nearPlane"></param>
/// <param name="farPlane"></param>
void GOAT_ENGINE::Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, glm::vec3(0.0f, 0.0f, 0.0f), Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	cameraMatrix = projection * view;
}

/// <summary>
/// Ne pas toucher sous peine de mort!!!
/// 
/// Cette m�thode sert � render la sc�ne en fonction de la position et l'angle de la cam�ra
/// </summary>
void GOAT_ENGINE::Camera::matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

/// <summary>
/// Cette m�thode sert � g�rer les d�placements de la cam�ra
/// </summary>
/// <param name="window">la fen�tre � �couter les touches du claviers</param>
void GOAT_ENGINE::Camera::move(GLFWwindow* window) {
	glm::vec3 up(0.0f, 1.0f, 0.0f);
	glm::vec3 orientation(0.0f, 0.0f, -1.0f);
	float speed(0.001f);

	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.04f;
	}
	else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.001f;
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position += speed * up;
	}

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position += speed * -glm::normalize(glm::cross(orientation, up));
	}

	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position += speed * -up;
	}

	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position += speed * glm::normalize(glm::cross(orientation, up));
	}
}