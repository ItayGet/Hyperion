#include "shapemanager.h"
#include <algorithm>

namespace Hyperion {
	void ShapeManager::addQueue(unsigned int index) {
		if (std::find(queue.begin(), queue.end(), index) == queue.end()) {
			queue.push_back(index);
		}
	}

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
		addQueue(index);
	}

	std::vector<unsigned int>* ShapeManager::getQueue() {
		return &queue;
	}
	void ShapeManager::clearQueue() {
		queue.clear();
	}
}