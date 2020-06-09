#include "hyperion.h"

namespace Hyperion {

	Hyperion::Hyperion(
		const char* windowName,
		int width,
		int height,
		bool& succ,
		GLFWwindow*& window
	) {
		initializer = std::unique_ptr<Initializer>(new Initializer(windowName, width, height, succ));

		window = initializer->getWindow();

		shapeManager = std::make_unique<ShapeManager>();
		renderer = std::make_unique<Renderer>(window, shapeManager->getShapes());
		uniformManager = std::make_unique<UniformManager>(renderer->getShader());
	}

	Hyperion::~Hyperion() {
		terminate();
	}

	GameObject Hyperion::addShape() {
		return shapeManager->addShape();
	}

	GameObject Hyperion::addShape(const Transformation& transformation, const glm::vec3& color, const glm::vec3& size, ShapeType type) {
		auto go = shapeManager->addShape();

		go.setTransformation(transformation);
		go.setColor(color);
		go.setSize(size);
		go.setType(type);

		return go;
	}

	Transformation& Hyperion::getCameraTransformation() {
		return shapeManager->getCameraTransformation();
	}

	//TODO:
	//void Hyperion::removeShape() {
	//	
	//}

	UniformManager& Hyperion::getUniformManager() {
		return *uniformManager;
	}

	bool Hyperion::update() {
		bool succ = renderer->update(*shapeManager->getQueue(), shapeManager->getTransformations(), shapeManager->getCameraTransformation());
		shapeManager->clearQueue();
		return succ;
	}

	void Hyperion::terminate() {

		initializer->terminate();
		renderer->terminate();
	}
}