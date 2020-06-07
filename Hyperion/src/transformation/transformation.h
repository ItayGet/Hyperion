#pragma once
#include "api.h"
#include "glm/glm.hpp"

namespace Hyperion {
	/// <summary>
	/// The representation of a transformation of a shape. It has a position and a rotation.
	/// </summary>
	class HPR_API Transformation {
	private:
		glm::vec3 translation;
		glm::vec3 rotation;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Transformation"/> class.
		/// </summary>
		Transformation();

		/// <summary>
		/// Initializes a new instance of the <see cref="Transformation"/> class based on existing values.
		/// </summary>
		/// <param name="translation">The translation.</param>
		/// <param name="rotation">The rotation.</param>
		Transformation(const glm::vec3& translation, const glm::vec3& rotation);

		/// <summary>
		/// Converts an instance of <see cref="Transformation" /> to a matrix.
		/// </summary>
		/// <param name="trans">The mat.</param>
		void toMatrix(const glm::mat4& mat);

		/// <summary>
		/// Rotates along the axes.
		/// </summary>
		/// <param name="axis">The axis.</param>
		/// <param name="angle">The angle.</param>
		void rotateAxes(const glm::vec3& axis, float angle);

		/// <summary>
		/// Adds <paramref cref="point" /> to the position of the instance.
		/// </summary>
		/// <param name="point">The point.</param>
		void translate(const glm::vec3& point);

		/// <summary>
		/// Gets the translation.
		/// </summary>
		/// <returns>The translation.</returns>
		glm::vec3 getTranslation();

		/// <summary>
		/// Sets the translation.
		/// </summary>
		/// <param name="translation">The translation.</param>
		void setTranslation(const glm::vec3& translation);

		/// <summary>
		/// Gets the rotation.
		/// </summary>
		/// <returns>The rotation</returns>
		glm::mat4 getRotation();

		/// <summary>
		/// Sets the rotation.
		/// </summary>
		/// <param name="rotation">The rotation.</param>
		void setRotation(const glm::mat4& rotation);
	};
}