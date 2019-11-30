#pragma once
#include "glm/glm.hpp"

namespace Hyperion {
	enum ShapeType {
		Circle,
		Square
	};
	struct Shape {
		glm::vec3 pos;
		float radius;
		glm::vec3 color;
		float padding;
 
		//glm::mat3x2 mat;
		//glm::vec3 color;
		//ShapeType type;
		//Texture texture;
	};

	struct ShapeData {
		Shape shapes[128];
		unsigned int size;
	};
}

