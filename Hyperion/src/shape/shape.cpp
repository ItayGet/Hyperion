#include "shape.h"

namespace Hyperion {
	Shape::Shape(glm::vec3 pos, float radius, glm::vec3 color) {
		this->pos = pos;
		this->radius = radius;
		this->color = color;
		this->padding = 0;
	}
	Shape::Shape() : pos(0), radius(0), color(0), padding(0) {}
}