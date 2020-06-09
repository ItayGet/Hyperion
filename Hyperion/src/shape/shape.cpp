#include "shape.h"

namespace Hyperion {
	Shape::Shape(const glm::mat4& transform, const glm::vec4& color, const glm::vec4& size, ShapeType type) {
		setTransform(transform);
		setSize(size);
		setColor(color);
		setType(type);
	}

	Shape::Shape() : transform(), size(), color(), type(), padding() {}

	void Shape::setTransform(const glm::mat4& transform) { this->transform = transform; }
	const glm::mat4& Shape::getTransform() { return transform; }

	void Shape::setSize(const glm::vec4& size) { this->size = size; }
	const glm::vec4& Shape::getSize() { return size; }

	void Shape::setColor(const glm::vec4& color) { this->color = color; }
	const glm::vec4& Shape::getColor() { return color; }

	void Shape::setType(ShapeType type) { this->type = (int)type; }
	ShapeType Shape::getType() { return (ShapeType)type; }
}