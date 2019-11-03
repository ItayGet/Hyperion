#include "initializer.h"

namespace Hyperion {
	Initializer::Initializer(const char* windowName, int width, int height, bool &succ) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		if (!glfwInit()) {
			succ = false;
			return;
		}

		window = glfwCreateWindow(width, height, windowName, NULL, NULL);
		if (!window) {
			succ = false;
			return;
		}

		glfwMakeContextCurrent(window);
		//otherwise it eats my battery away
		//glfwSwapInterval(1);


		if (glewInit() != GLEW_OK) {
			succ = false;
			return;
		}
		succ = true;
	}

	void Initializer::terminate() {
		glfwTerminate();
		glfwDestroyWindow(window);
	}

	Initializer::~Initializer() {
		terminate();
	}

	GLFWwindow* Initializer::getWindow() {
		return window;
	}
}