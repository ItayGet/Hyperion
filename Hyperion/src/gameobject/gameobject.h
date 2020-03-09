#pragma once
#include "api.h"
#include "transformation/transformation.h"
#include "shapemanager/shapemanager.h"
#include "shape/shape.h"

namespace Hyperion {
	class HPR_API GameObject {
	private:
		ShapeManager* sm;
		unsigned int index;
		Shape& getShape();
		void informUpdate();
		Transformation& getTransformation();

	public:

		GameObject();
		void _wireSm(ShapeManager* sm, unsigned int index);

		void clearTranslation(glm::mat4& mat);

		const glm::mat4& getTransform();
		void setTranform(const glm::mat4& transform);

		const glm::vec3& getColor();
		void setColor(const glm::vec3& color);

		float getRadius();
		void setRadius(float radius);

		ShapeType getType();
		void setType(ShapeType type);

		void rotate(const glm::vec3& axis, float angle);
		void rotateAxes(const glm::vec3& axis, float angle);
		void translate(const glm::vec3& point);

		glm::vec3 getTranslation();
		void setTranslation(const glm::vec3& translation);

		glm::mat4 getRotation();
		void setRotation(const glm::mat4& rotation);
	};
}