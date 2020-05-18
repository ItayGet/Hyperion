#pragma once
#include "api.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "shape/shape.h"
#include "shader/shader.h"
#include <vector>

namespace Hyperion {
	/// <summary>
	/// Manages the library's window and initializes <see cref="Shader"/> instances.
	/// </summary>
	class HPR_API Renderer {
	private:

		GLFWwindow* window;
		bool exit = false;
		unsigned int vao = 0, vbo = 0, ebo = 0;

		unsigned int shapesBlock = 0;
		Shader shader;
		ShapeData* shapeData;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Renderer"/> class.
		/// </summary>
		/// <param name="window">A GLFWwindow instance.</param>
		/// <param name="shapes">A pointer to the shapes' data, which is controlled by <see cref="ShapeManager"/>.</param>
		Renderer(GLFWwindow* window, ShapeData* shapes = nullptr);

		/// <summary>
		/// Sets the shape data.
		/// </summary>
		/// <param name="shapeData">The shape data.</param>
		void setShapeData(ShapeData* shapeData);
		~Renderer();

		/// <summary>
		/// Gets the shader.
		/// </summary>
		/// <returns>The Shader.</returns>
		Shader& getShader();

		/// <summary>
		/// Terminates this instance.
		/// </summary>
		void terminate();

		/// <summary>
		/// Updates the specified indexes to update.
		/// </summary>
		/// <param name="indexesToUpdate">A list of indexes to the shape data that are needed to be sent to the GPU.</param>
		/// <returns>Whether the update was successful.</returns>
		bool update(std::vector<unsigned int>& indexesToUpdate);
	};

}