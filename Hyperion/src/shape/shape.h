#pragma once
#include "api.h"
#include "glm/glm.hpp"

#define HPR_MAX_SHAPES 128

namespace Hyperion {
	/// <summary>
	/// The different types of shapes the library supports
	/// </summary>
	enum class ShapeType : int {
		Sphere = 0,
		Square = 1
	};

	/// <summary>
	/// The internal represntation of a shape. This is also how the GPU views a shape.
	/// </summary>
	class HPR_API Shape {
	private:
		/// <summary>
		/// The transformation matrix of the shape.
		/// </summary>
		glm::mat4 transform;

		/// <summary>
		/// The color of the shape.
		/// </summary>
		glm::vec4 color;

		/// <summary>
		/// The radius of the shape.
		/// </summary>
		float radius;

		/// <summary>
		/// The type of the shape.
		/// </summary>
		int type;

		/// <summary>
		/// Padding due to how std140 transfers uniforms.
		/// </summary>
		float padding[2];

		//glm::vec3 pos;
		//glm::vec3 rotation;
		//glm::vec3 scaling;
		//glm::vec3 color;
		//ShapeType type;
		//Texture texture;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Shape"/> class.
		/// </summary>
		/// <param name="transform">The transform.</param>
		/// <param name="color">The color.</param>
		/// <param name="radius">The radius.</param>
		/// <param name="type">The type.</param>
		Shape(glm::mat4 transform, glm::vec4 color, float radius, ShapeType type);

		/// <summary>
		/// Initializes a new instance of the <see cref="Shape"/> class.
		/// </summary>
		Shape();

		/// <summary>
		/// Sets the transformation matrix of the shape.
		/// </summary>
		/// <param name="transform">The transformation matrix.</param>
		void setTransform(const glm::mat4& transform);

		/// <summary>
		/// Gets the transformation matrix of the shape.
		/// </summary>
		/// <returns>The transformation matrix.</returns>
		const glm::mat4& getTransform();

		/// <summary>
		/// Sets the radius of the shape.
		/// </summary>
		/// <param name="radius">The radius.</param>
		void setRadius(float radius);

		/// <summary>
		/// Gets the radius of the shape.
		/// </summary>
		/// <returns>The radius.</returns>
		float getRadius();

		/// <summary>
		/// Sets the color of the shape.
		/// </summary>
		/// <param name="color">The color.</param>
		void setColor(const glm::vec4& color);

		/// <summary>
		/// Gets the color of the shape.
		/// </summary>
		/// <returns>The color.</returns>
		const glm::vec4& getColor();

		/// <summary>
		/// Sets the type of the shape.
		/// </summary>
		/// <param name="type">The type.</param>
		void setType(ShapeType type);

		/// <summary>
		/// Gets the type of the shape.
		/// </summary>
		/// <returns>The type.</returns>
		ShapeType getType();
	};

	/// <summary>
	/// The actual data that is transfered to the GPU.
	/// </summary>
	struct HPR_API ShapeData {
		/// <summary>
		/// The shapes.
		/// </summary>
		Shape shapes[HPR_MAX_SHAPES];

		/// <summary>
		/// The amount of shapes being displayed right now.
		/// </summary>
		unsigned int size;
	};
}

