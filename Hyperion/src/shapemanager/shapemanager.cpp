#include "shapemanager.h"

namespace Hyperion {
	ShapeManager::ShapeManager() {
		shapes.size = 0;
	}

	ShapeManager::~ShapeManager() {

	}

	void ShapeManager::setShapes(ShapeData shapes) {
		this->shapes = shapes;
	}

	ShapeData* ShapeManager::getShapes() {
		return &shapes;
	}

	void ShapeManager::addShape(Shape shape) {
		setShape(shapes.size++, shape);
	}

	void ShapeManager::removeShape() {
		shapes.size--;
	}

	Shape ShapeManager::getShape(int index) {
		return shapes.shapes[index];
	}

	void ShapeManager::setShape(int index, Shape shape) {
		shapes.shapes[index] = shape;
	}
}