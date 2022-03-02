#include "Event.h"

Event::Event(GLFWwindow* _win) : win(_win) {
}

void Event::onPress(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_PRESS) {
		func(g);
	}
}

void Event::onPress(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_PRESS) {
		func();
	}
}

void Event::onRepeat(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_REPEAT) {
		func(g);
	}
}

void Event::onRepeat(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_REPEAT) {
		func();
	}
}

void Event::onRelease(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_RELEASE) {
		func(g);
	}
}

void Event::onRelease(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));

	if (state == GLFW_RELEASE) {
		func();
	}
}

glm::vec2 Event::getMousePosition() {
	double x, y;
	glfwGetCursorPos(this->win, &x, &y);
	return glm::vec2(x, y);
}

void Event::onMouseClick(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state = glfwGetMouseButton(this->win, key);

	if (state == GLFW_PRESS) {
		func(g);
	}
}

void Event::onMouseClick(int key, void(*func)()) {
	int state = glfwGetMouseButton(this->win, key);

	if (state == GLFW_PRESS) {
		func();
	}
}
