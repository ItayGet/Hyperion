#pragma once
#include "api.h"
#include "glm/glm.hpp"

namespace Hyperion {
	enum class ShapeType : int {
		Sphere = 0,
		Square = 1
	};

	class HPR_API Shape {
	private:
		glm::mat4 transform;
		glm::vec4 color;
		float radius;
		int type;
		float padding[2];

		//glm::vec3 pos;
		//glm::vec3 rotation;
		//glm::vec3 scaling;
		//glm::vec3 color;
		//ShapeType type;
		//Texture texture;
	public:
		Shape(glm::mat4 transform, glm::vec4 color, float radius, ShapeType type);
		Shape();

		// Setters and getters
		void setTransform(glm::mat4 transform);
		glm::mat4 getTransform();

		void setRadius(float radius);
		float getRadius();

		void setColor(glm::vec4 color);
		glm::vec4 getColor();

		void setType(ShapeType type);
		ShapeType getType();
	};

	struct HPR_API ShapeData {
		Shape shapes[128];
		unsigned int size;
	};
}

