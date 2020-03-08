#include "shapemanager.h"
#include "gameobject/gameobject.h"
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

	ShapeData* ShapeManager::getShapes() {
		return &shapes;
	}

	GameObject ShapeManager::addShape() {
		GameObject go{};
		go._wireSm(this, shapes.size++);
		return go;
	}

	//void ShapeManager::removeShape(GameObject go) {
	//	shapes.size--;
	//}

	std::vector<unsigned int>* ShapeManager::getQueue() {
		return &queue;
	}

	void ShapeManager::clearQueue() {
		queue.clear();
	}
}