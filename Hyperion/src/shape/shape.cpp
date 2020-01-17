#include "shape.h"

namespace Hyperion {
	Shape::Shape(glm::mat4 transform, glm::vec4 color, float radius, ShapeType type) {
		setTransform(transform);
		setRadius(radius);
		setColor(color);
		setType(type);
	}

	Shape::Shape() : transform(), radius(0), color(0), type(0), padding() {}

	void Shape::setTransform(glm::mat4 transform) { this->transform = transform; }
	glm::mat4 Shape::getTransform() { return transform; }

	void Shape::setRadius(float radius) { this->radius = radius; }
	float Shape::getRadius() { return radius; }

	void Shape::setColor(glm::vec4 color) { this->color = color; }
	glm::vec4 Shape::getColor() { return color; }

	void Shape::setType(ShapeType type) { this->type = (int)type; }
	ShapeType Shape::getType() { return (ShapeType)type; }
}