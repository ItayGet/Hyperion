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
		void toMatrix(glm::mat4& mat) const;

		void toMatrixCamera(glm::mat4& mat) const;

		/// <summary>
		/// Gets the translation.
		/// </summary>
		/// <returns>The translation.</returns>
		const glm::vec3& getTranslation() const;

		/// <summary>
		/// Sets the translation.
		/// </summary>
		/// <param name="translation">The translation.</param>
		void setTranslation(const glm::vec3& translation);

		/// <summary>
		/// Gets the rotation.
		/// </summary>
		/// <returns>The rotation.</returns>
		const glm::vec3& getRotation() const;

		/// <summary>
		/// Sets the rotation.
		/// </summary>
		/// <param name="rotation">The rotation.</param>
		void setRotation(const glm::vec3& rotation);
	};
}