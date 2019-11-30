#pragma once
#include "api.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Hyperion {
	class HPR_API Initializer {
	private:
		GLFWwindow* window = NULL;
	public:
		Initializer(const char* windowName, int width, int height, bool& succ);
		~Initializer();
		void terminate();
		GLFWwindow* getWindow();
	};

}