#pragma once
#include "api.h"
#include "glm/glm.hpp"

namespace Hyperion {
	class HPR_API Transformation {
	private:
		glm::mat4 mat;
		void multiplyByMat(const glm::mat4& mat);

	public:
		static Transformation& toTransformation(glm::mat4& mat);
		static glm::mat4& toMatrix(Transformation& trans);

		void clearTranslation(glm::mat4& mat);

		void rotate(const glm::vec3& axis, float angle);
		void translate(const glm::vec3& point);

		glm::vec3 getTranslation();
		void setTranslation(const glm::vec3& translation);

		glm::mat4 getRotation();
		void setRotation(const glm::mat4& rotation);
	};
}