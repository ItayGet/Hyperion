#pragma once
#include "api.h"
#include "shapemanager/shapemanager.h"
#include "shape/shape.h"

namespace Hyperion {
	class HPR_API GameObject {
	private:
		ShapeManager* sm;
		unsigned int index;
		Shape& getShape();
		void informUpdate();
		void multiplyByMat(const glm::mat4& mat);

	public:
		GameObject();
		void _wireSm(ShapeManager* sm, unsigned int index);

		glm::mat4 getTransform();
		void setTranform(glm::mat4 transform);

		glm::vec3 getColor();
		void setColor(glm::vec3 color);

		float getRadius();
		void setRadius(float radius);

		ShapeType getType();
		void setType(ShapeType type);

		void rotate(glm::vec3 axis, float angle);
		void translate(glm::vec3 point);
	};
}