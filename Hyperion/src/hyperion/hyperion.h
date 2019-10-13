#pragma once
#include "renderer/renderer.h"
#include "initializer/initializer.h"
#include <memory>

namespace Hyperion {
	class HPR_API Hyperion {
	private:
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<Initializer> initializer;
	public:
		Hyperion(
			const char* windowName,
			int width,
			int height,
			bool &succ
		);
		~Hyperion();
		bool Update();
		void terminate();
	};
}

