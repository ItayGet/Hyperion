#pragma once
#include "api.h"
#include "shape/shape.h"
#include <vector>

namespace Hyperion {
	class GameObject;

	class HPR_API ShapeManager {
	private:
		ShapeData shapes;
		std::vector<unsigned int> queue;
	public:

		ShapeManager();
		~ShapeManager();
		void addQueue(unsigned int index);
		ShapeData* getShapes();
		GameObject addShape();
		//void removeShape(GameObject go);
		std::vector<unsigned int>* getQueue();
		void clearQueue();
	};
}