#pragma once
#include "api.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Hyperion {
	/// <summary>
	/// Initializes the openGL context and creates a window.
	/// </summary>
	class HPR_API Initializer {
	private:
		GLFWwindow* window = NULL;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Initializer"/> class.
		/// </summary>
		/// <param name="windowName">Name of the window.</param>
		/// <param name="width">The width of the window.</param>
		/// <param name="height">The height of the window.</param>
		/// <param name="succ">Whether initialization suceeded.</param>
		Initializer(const char* windowName, int width, int height, bool& succ);

		~Initializer();

		/// <summary>
		/// Terminates this instance.
		/// </summary>
		void terminate();

		/// <summary>
		/// Gets the window.
		/// </summary>
		/// <returns>The window.</returns>
		GLFWwindow* getWindow();
	};

}