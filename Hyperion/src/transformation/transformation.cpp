#include "transformation.h"
#include "glm/gtx/transform.hpp"

namespace Hyperion {
	Transformation::Transformation() : Transformation(glm::mat4(1.)) {}

	Transformation::Transformation(const glm::mat4& mat) {
		this->mat = mat;
	}

	void Transformation::multiplyByMat(const glm::mat4& mat) {
		this->mat *= mat;
	}


	Transformation& Transformation::toTransformation(glm::mat4& mat) {
		return (Transformation&)mat;
	}

	glm::mat4& Transformation::toMatrix(Transformation& trans) {
		return (glm::mat4&)trans;
	}

	void Transformation::clearTranslation(glm::mat4& mat) {
		mat[3] = glm::vec4(glm::vec3(0.), 1.);
	}

	// Rotate along origin of shape
	void Transformation::rotate(const glm::vec3& axis, float angle) {
		auto pos = getTranslation();

		clearTranslation(mat);

		mat = glm::rotate(mat, angle, axis);
		mat = glm::translate(mat, pos);
	}

	void Transformation::rotateAxes(const glm::vec3& axis, float angle) {
		mat = glm::rotate(mat, angle, axis);
	}

	void Transformation::translate(const glm::vec3& point) {
		multiplyByMat(glm::translate(glm::mat4(1.), point));
	}

	glm::vec3 Transformation::getTranslation() {
		return glm::vec3(glm::inverse(mat) * glm::vec4(glm::vec3(0.), 1.)) * -1.f;
	}

	void Transformation::setTranslation(const glm::vec3& translation) {
		clearTranslation(mat);
		translate(translation);
	}

	glm::mat4 Transformation::getRotation() {
		glm::mat4 tmp = mat;
		clearTranslation(tmp);
		return tmp;
	}

	void Transformation::setRotation(const glm::mat4& rotation) {
		glm::vec3 pos = getTranslation();
		mat = rotation;
		setTranslation(pos);
	}
}