#pragma once
#include "api.h"
#include "transformation/transformation.h"
#include "shapemanager/shapemanager.h"
#include "shape/shape.h"

namespace Hyperion {
	/// <summary>
	/// A library-user friendly representatiton of a shape.
	/// </summary>
	class HPR_API GameObject {
	private:
		/// <summary>
		/// The <see cref="ShapeManager" /> where the shape is stored.
		/// </summary>
		ShapeManager* sm;

		/// <summary>
		/// The index of the shape inside the  <see cref="ShapeData" />.
		/// </summary>
		unsigned int index;

		/// <summary>
		/// Gets the shape the <see cref="GameObject" /> represents.
		/// </summary>
		/// <returns>The shape.</returns>
		Shape& getShape();

		/// <summary>
		/// Informs the <see cref="ShapeManager" /> this shape needs to be updated.
		/// </summary>
		void informUpdate();

	public:

		/// <summary>
		/// Initializes a new instance of the <see cref="GameObject"/> class.
		/// </summary>
		GameObject();

		/// <summary>
		/// Wires the <see cref="ShapeManager" />. Not a library-user function.
		/// </summary>
		/// <param name="sm">The <see cref="ShapeManager" /></param>
		/// <param name="index">The index.</param>
		void _wireSm(ShapeManager* sm, unsigned int index);

		/// <summary>
		/// Gets the transformation of the shape.
		/// </summary>
		/// <returns>The transformation.</returns>
		const Transformation& getTransformation();

		/// <summary>
		/// Sets the transformation of the shape.
		/// </summary>
		/// <param name="transform">The transformation.</param>
		void setTransformation(const Transformation& transformation);

		/// <summary>
		/// Gets the color of the shape.
		/// </summary>
		/// <returns>The color</returns>
		const glm::vec3& getColor();

		/// <summary>
		/// Sets the color of the shape.
		/// </summary>
		/// <param name="color">The color.</param>
		void setColor(const glm::vec3& color);

		/// <summary>
		/// Gets the radius of the shpae.
		/// </summary>
		/// <returns>The radius</returns>
		float getRadius();

		/// <summary>
		/// Sets the radius of the shape.
		/// </summary>
		/// <param name="radius">The radius.</param>
		void setRadius(float radius);

		/// <summary>
		/// Gets the type of the shape.
		/// </summary>
		/// <returns>The type.</returns>
		/// <seealso cref="ShapeType">
 		ShapeType getType();

		/// <summary>
		/// Sets the type of the shape.
		/// </summary>
		/// <param name="type">The type.</param>
		/// <seealso cref="ShapeType">
		void setType(ShapeType type);

		/// <summary>
		/// Sets the translation of the shape.
		/// </summary>
		/// <param name="translation">The translation of the shape.</param>
		void setTranslation(const glm::vec3& translation);

		/// <summary>
		/// Sets the rotation of the shape.
		/// </summary>
		/// <param name="rotation">The rotation of the shape.</param>
		void setRotation(const glm::vec3& rotation);
	};
}