#pragma once
#include "shape/shape.h"
#include "api.h"

namespace Hyperion {
	class HPR_API ShapeManager {
	private:
		ShapeData shapes;
	public:
		ShapeManager();
		~ShapeManager();
		void setShapes(ShapeData shapes);
		ShapeData* getShapes();
		void addShape(Shape shape);
		void removeShape();
		Shape getShape(int index);
		void setShape(int index, Shape shape);
	};
}