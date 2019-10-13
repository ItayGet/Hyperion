#pragma once
#include "api.h"
#include "shader/shader.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Hyperion {
	class HPR_API HPRCore {
	private:
		GLFWwindow* window = NULL;
		bool exit = false;
		void terminate();
		unsigned int vao = 0, vbo = 0, ebo = 0;
	public:
		HPRCore();
		bool Update();
	};

}