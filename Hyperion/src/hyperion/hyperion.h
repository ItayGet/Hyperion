#pragma once
#include "renderer/renderer.h"
#include "initializer/initializer.h"
#include "shape/shape.h"
#include "shapemanager/shapemanager.h"
#include "gameobject/gameobject.h"
#include "uniformmanager/uniformmanager.h"
#include <memory>

namespace Hyperion {
	class HPR_API Hyperion {
	private:
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<Initializer> initializer;
		std::unique_ptr<ShapeManager> shapeManager;
		std::unique_ptr<UniformManager> uniformManager;

	public:
		Hyperion(
			const char* windowName,
			int width,
			int height,
			bool& succ,
			GLFWwindow*& window
		);
		~Hyperion();

		GameObject addShape();
		void removeShape(GameObject go);
		UniformManager& getUniformManager();

		bool update();
		void terminate();
	};
}


