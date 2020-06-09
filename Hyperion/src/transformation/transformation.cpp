#include "transformation.h"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/euler_angles.hpp"

inline glm::vec3 wrapAngle(const glm::vec3& angle)
{
	const float twoPi = 2 * glm::pi<float>();
	return angle - twoPi * floor(angle / twoPi);
}

namespace Hyperion {
	Transformation::Transformation() : translation(1.), rotation(1.) {}

	Transformation::Transformation(const glm::vec3& translation, const glm::vec3& rotation) {
		setTranslation(translation);
		setRotation(rotation);
	}

	void Transformation::toMatrix(glm::mat4& mat) const {
		mat = glm::mat4(1.);
		mat *= glm::yawPitchRoll(rotation.x, rotation.y, rotation.z);
		mat = glm::translate(mat, translation);
	}

	void Transformation::toMatrixCamera(glm::mat4& mat) const {
		mat = glm::mat4(1.);
		mat = glm::translate(mat, translation);
		mat *= glm::yawPitchRoll(rotation.x, rotation.y, rotation.z);
	}

	const glm::vec3& Transformation::getTranslation() const {
		return translation;
	}

	void Transformation::setTranslation(const glm::vec3& translation) {
		this->translation = translation;
	}

	const glm::vec3& Transformation::getRotation() const {
		return rotation;
	}

	void Transformation::setRotation(const glm::vec3& rotation) {
		this->rotation = wrapAngle(rotation);
	}
}