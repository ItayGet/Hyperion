#pragma once
#include "api.h"
#include "glm/glm.hpp"

namespace Hyperion {
	enum ShapeType {
		Circle,
		Square
	};
	struct HPR_API Shape {
		glm::vec3 pos;
		float radius;
		glm::vec3 color;
		float padding;
 
		//glm::vec3 pos;
		//glm::vec3 rotation;
		//glm::vec3 scaling;
		//glm::vec3 color;
		//ShapeType type;
		//Texture texture;

		Shape(glm::vec3 pos, float radius, glm::vec3 color);
		Shape();
	};

	struct HPR_API ShapeData {
		Shape shapes[128];
		unsigned int size;
	};
}

