#pragma once
#include "renderer/renderer.h"
#include "initializer/initializer.h"
#include "shape/shape.h"
#include "shapemanager/shapemanager.h"
#include "gameobject/gameobject.h"
#include "uniformmanager/uniformmanager.h"
#include <memory>

namespace Hyperion {
	/// <summary>
	/// The <c>Hyperion</c> class houses the interface for the manipulation of shapes.
	/// It uses the internal classes <see cref="Renderer"/>, <see cref="Initializer"/>, <see cref="ShapeManager"/> and <see cref="UniformManager"/>.
	/// </summary>
	class HPR_API Hyperion {
	private:
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<Initializer> initializer;
		std::unique_ptr<ShapeManager> shapeManager;
		std::unique_ptr<UniformManager> uniformManager;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Hyperion"/> class.
		/// </summary>
		/// <param name="windowName">Name of the window.</param>
		/// <param name="width">The width of the window.</param>
		/// <param name="height">The height of the window.</param>
		/// <param name="succ">Whether initialization suceeded.</param>
		Hyperion(
			const char* windowName,
			int width,
			int height,
			bool& succ,
			GLFWwindow*& window
		);
		~Hyperion();

		/// <summary>
		/// Adds a shape.
		/// </summary>
		/// <returns>The newly added shape.</returns>
		GameObject addShape();

		/// <summary>
		/// Adds a shape.
		/// </summary>
		/// <param name="transformation">The transformation.</param>
		/// <param name="color">The color.</param>
		/// <param name="size">The size.</param>
		/// <param name="type">The type.</param>
		/// <returns>The newly added shape.</returns>
		GameObject addShape(const Transformation& transformation, const glm::vec3& color, const glm::vec3& size, ShapeType type);

		/// <summary>
		/// Gets the camera transformation, can be modified.
		/// </summary>
		/// <returns>The camera transformation.</returns>
		Transformation& getCameraTransformation();

		void removeShape(GameObject go);

		/// <summary>
		/// Allows access to the window's UniformManager. See <see cref="UniformManager"/> for more.
		/// </summary>
		/// <returns>The uniform manager.</returns>
		UniformManager& getUniformManager();

		/// <summary>
		/// Updates this instance.
		/// </summary>
		/// <returns>Whether the update was successful.</returns>
		bool update();

		/// <summary>
		/// Terminates this instance.
		/// </summary>
		void terminate();
	};
}


