#include "hyperion.h"

namespace Hyperion {
	Hyperion::Hyperion(
		const char* windowName,
		int width,
		int height,
		bool& succ
	) {
		initializer = std::unique_ptr<Initializer>(new Initializer(windowName, width, height, succ));
		shapeManager = std::unique_ptr<ShapeManager>(new ShapeManager());
		renderer = std::unique_ptr<Renderer>(new Renderer(initializer->getWindow(), shapeManager->getShapes()));
	}

	Hyperion::~Hyperion() {
		terminate();
	}

	void Hyperion::addShape(Shape shape) {
		shapeManager->addShape(shape);
	}

	void Hyperion::removeShape() {
		shapeManager->removeShape();
	}

	Shape Hyperion::getShape(int index) {
		return shapeManager->getShape(index);
	}

	void Hyperion::setShape(int index, Shape shape) {
		shapeManager->setShape(index, shape);
	}

	bool Hyperion::update() {
		return renderer->update();
	}

	void Hyperion::terminate() {
		initializer->terminate();
		renderer->terminate();
	}
}