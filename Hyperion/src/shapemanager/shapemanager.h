#pragma once
#include "shape/shape.h"
#include "api.h"
#include <vector>

namespace Hyperion {
	class HPR_API ShapeManager {
	private:
		ShapeData shapes;
		std::vector<unsigned int> queue;
		void addQueue(unsigned int index);
	public:
		ShapeManager();
		~ShapeManager();
		void setShapes(ShapeData shapes);
		ShapeData* getShapes();
		void addShape(Shape shape);
		void removeShape();
		Shape getShape(int index);
		void setShape(int index, Shape shape);
		std::vector<unsigned int>* getQueue();
		void clearQueue();
	};
}