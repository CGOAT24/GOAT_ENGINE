#include "Camera.h"

GOAT_ENGINE::Camera::Camera(int _width, int _height, glm::vec3 _position) {
	Camera::width = _width;
	Camera::height = _height;
	position = _position;
}

void GOAT_ENGINE::Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, glm::vec3(0.0f, 0.0f, 0.0f), Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void GOAT_ENGINE::Camera::matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

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