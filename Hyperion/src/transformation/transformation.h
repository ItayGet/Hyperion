#pragma once
#include "api.h"
#include "glm/glm.hpp"

namespace Hyperion {
	/// <summary>
	/// The representation of a transformation of a shape. It has a position and a rotation.
	/// </summary>
	class HPR_API Transformation {
	private:
		glm::mat4 mat;
		void multiplyByMat(const glm::mat4& mat);

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Transformation"/> class.
		/// </summary>
		Transformation();

		/// <summary>
		/// Initializes a new instance of the <see cref="Transformation"/> class based on an existing matrix.
		/// </summary>
		/// <param name="mat">The matrix.</param>
		Transformation(const glm::mat4& mat);

		/// <summary>
		/// Initializes a new instance of the <see cref="Transformation" /> class based on an existing matrix.
		/// </summary>
		/// <param name="mat">The matrix.</param>
		/// <returns>The new <see cref="Transformation" /> instance</returns>
		static Transformation& toTransformation(glm::mat4& mat);

		/// <summary>
		/// Converts an instance of <see cref="Transformation" /> to a matrix.
		/// </summary>
		/// <param name="trans">The transformation.</param>
		/// <returns>The new matrix</returns>
		static glm::mat4& toMatrix(Transformation& trans);

		/// <summary>
		/// Clears the translation off the matrix.
		/// </summary>
		/// <param name="mat">The matrix.</param>
		void clearTranslation(glm::mat4& mat);

		/// <summary>
		/// Rotates along the position.
		/// </summary>
		/// <param name="axis">The axis.</param>
		/// <param name="angle">The angle.</param>
		void rotate(const glm::vec3& axis, float angle);

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