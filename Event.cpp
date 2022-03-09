#include "Event.h"

GOAT_ENGINE::Event::Event(GLFWwindow* _win) : win(_win) {
}

void GOAT_ENGINE::Event::onPress(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_PRESS)
		func(g);
}

void GOAT_ENGINE::Event::onPress(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_PRESS) 
		func();
}

void GOAT_ENGINE::Event::onRepeat(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_REPEAT)
		func(g);
}

void GOAT_ENGINE::Event::onRepeat(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_REPEAT)
		func();
}

void GOAT_ENGINE::Event::onRelease(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_RELEASE)
		func(g);
}

void GOAT_ENGINE::Event::onRelease(int key, void(*func)()) {
	int state(glfwGetKey(this->win, key));
	if (state == GLFW_RELEASE)
		func();
}

glm::vec2 GOAT_ENGINE::Event::getMousePosition() {
	double x, y;
	glfwGetCursorPos(this->win, &x, &y);
	return glm::vec2(x, y);
}

void GOAT_ENGINE::Event::onMouseClick(int key, GameObject& g, void(*func)(GameObject& g)) {
	int state = glfwGetMouseButton(this->win, key);
	if (state == GLFW_PRESS)
		func(g);
}

void GOAT_ENGINE::Event::onMouseClick(int key, void(*func)()) {
	int state = glfwGetMouseButton(this->win, key);
	if (state == GLFW_PRESS)
		func();
}
