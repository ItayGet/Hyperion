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
		glm::vec3 pos;
		float radius;
		glm::vec3 color;
		int type;

		//glm::vec3 pos;
		//glm::vec3 rotation;
		//glm::vec3 scaling;
		//glm::vec3 color;
		//ShapeType type;
		//Texture texture;
	public:
		Shape(glm::vec3 pos, float radius, glm::vec3 color, ShapeType type);
		Shape();

		// Setters and getters
		void setPos(glm::vec3 pos);
		glm::vec3 getPos();

		void setRadius(float radius);
		float getRadius();

		void setColor(glm::vec3 color);
		glm::vec3 getColor();

		void setType(ShapeType type);
		ShapeType getType();
	};

	struct HPR_API ShapeData {
		Shape shapes[128];
		unsigned int size;
	};
}

