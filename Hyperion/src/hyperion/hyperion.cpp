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

	GameObject Hyperion::addShape() {
		return shapeManager->addShape();
	}

	//void Hyperion::removeShape() {
	//	
	//}

	bool Hyperion::update() {
		bool succ = renderer->update(*shapeManager->getQueue());
		shapeManager->clearQueue();
		return succ;
	}

	void Hyperion::terminate() {
		initializer->terminate();
		renderer->terminate();
	}
}