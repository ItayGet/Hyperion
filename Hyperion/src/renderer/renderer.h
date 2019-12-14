#pragma once
#include "api.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "shape/shape.h"
#include <vector>

namespace Hyperion {
	class HPR_API Renderer {
	private:

		GLFWwindow* window;
		bool exit = false;
		unsigned int shaderProg = 0;
		unsigned int vao = 0, vbo = 0, ebo = 0;

		unsigned int shader = 0, shapesBlock = 0;
		ShapeData* shapeData;
	public:
		Renderer(GLFWwindow* window, ShapeData* shapes = nullptr);
		void setShapeData(ShapeData* shapeData);
		~Renderer();
		void terminate();
		bool update(std::vector<unsigned int>& indexesToUpdate);
	};

}