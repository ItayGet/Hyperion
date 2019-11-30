#pragma once
#include "renderer/renderer.h"
#include "initializer/initializer.h"
#include "shape/shape.h"
#include "shapemanager/shapemanager.h"
#include <memory>

namespace Hyperion {
	class HPR_API Hyperion {
	private:
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<Initializer> initializer;
		std::unique_ptr<ShapeManager> shapeManager;
	public:
		Hyperion(
			const char* windowName,
			int width,
			int height,
			bool &succ
		);
		~Hyperion();
		void addShape(Shape shape);
		void removeShape();
		Shape getShape(int index);
		void setShape(int index, Shape shape);
		bool update();
		void terminate();
		
	};
}

