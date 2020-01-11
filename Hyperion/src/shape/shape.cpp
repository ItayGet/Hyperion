#include "shape.h"

namespace Hyperion {
	Shape::Shape(glm::vec3 pos, float radius, glm::vec3 color, ShapeType type) {
		setPos(pos);
		setRadius(radius);
		setColor(color);
		setType(type);
	}

	Shape::Shape() : pos(0), radius(0), color(0), type(0) {}

	void Shape::setPos(glm::vec3 pos) { this->pos = pos; }
	glm::vec3 Shape::getPos() { return pos; }

	void Shape::setRadius(float radius) { this->radius = radius; }
	float Shape::getRadius() { return radius; }

	void Shape::setColor(glm::vec3 color) { this->color = color; }
	glm::vec3 Shape::getColor() { return color; }

	void Shape::setType(ShapeType type) { this->type = (int)type; }
	ShapeType Shape::getType() { return (ShapeType)type; }
}