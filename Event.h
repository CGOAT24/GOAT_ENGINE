#ifndef EVENT_CLASS_H
#define EVENT_CLASS_H

#include "GameObject.h"
#include <functional>

namespace GOAT_ENGINE {
	class Event {
	private:
		GLFWwindow* win;
	public:
		Event(GLFWwindow* _win);

		//Keyboard event listeners
		void onPress(int key, GameObject& g, void (*func)(GameObject& g));
		void onPress(int key, void(*func)());
		void onRepeat(int key, GameObject& g, void (*func)(GameObject& g));
		void onRepeat(int key, void (*func)());
		void onRelease(int key, GameObject& g, void (*func)(GameObject& g));
		void onRelease(int key, void (*func)());

		//Mouse event listeners
		glm::vec2 getMousePosition();
		void onMouseClick(int key, GameObject& g, void (*func)(GameObject& g));
		void onMouseClick(int key, void (*func)());
	};
}


#endif