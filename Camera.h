#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "shaderClass.h"

class Camera {
private:
	glm::mat4 cameraMatrix = glm::mat4(1.0f);
	int width;
	int height;

public:
	glm::vec3 position;
	Camera(int width, int height, glm::vec3 position);
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);
};
#endif
