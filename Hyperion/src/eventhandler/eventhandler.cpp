#include "eventhandler/eventhandler.h"

namespace Hyperion {
	EventHandler::EventHandler(
		const char* windowName,
		int width,
		int height,
		bool& succ
	) : graphics(windowName, width, height, succ, window) {
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, keyPress);
	}

	EventHandler::~EventHandler() {
		onTerminate();

		graphics.terminate();
	}

	void EventHandler::update() {
		while (graphics.update()) {
			onUpdate();
		}
	}

	KeyState EventHandler::getKeyState(KeyCode key) {
		return (KeyState)(glfwGetKey(window, (int)key));
	}

	void EventHandler::onUpdate() {}
	void EventHandler::onKeyPress(KeyCode key, KeyState state) {}
	void EventHandler::onTerminate() {}

	EventHandler& windowToHandler(GLFWwindow* window) {
		return *(EventHandler*)glfwGetWindowUserPointer(window);
	}
}

void keyPress(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Hyperion::windowToHandler(window).onKeyPress((Hyperion::KeyCode)key, (Hyperion::KeyState)action);
}