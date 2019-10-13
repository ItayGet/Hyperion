#include "hyperion.h"

namespace Hyperion {
	Hyperion::Hyperion(
		const char* windowName,
		int width,
		int height,
		bool& succ
	) {
		initializer = std::unique_ptr<Initializer>(new Initializer(windowName, width, height, succ));
		renderer = std::unique_ptr<Renderer>(new Renderer(initializer->getWindow()));
	}

	void Hyperion::terminate() {
		initializer->terminate();
		renderer->terminate();
	}

	bool Hyperion::Update() {
		return renderer->Update();
	}

	Hyperion::~Hyperion() {
		terminate();
	}
}