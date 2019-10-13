#pragma once
#include "api.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Hyperion {
	class HPR_API Renderer {
	private:
		GLFWwindow* window;
		bool exit = false;
		int shaderProg = 0;
		unsigned int vao = 0, vbo = 0, ebo = 0;
	public:
		Renderer(GLFWwindow* window);
		virtual ~Renderer();
		void terminate();
		bool Update();
	};

}