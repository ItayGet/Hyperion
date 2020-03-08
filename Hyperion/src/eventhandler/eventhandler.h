#pragma once
#include "api.h"
#include "hyperion/hyperion.h"
#include "keyprops/keycode.h"
#include "keyprops/keystate.h"

namespace Hyperion {
	// This class needs to be inherited in order to use the library in the intended way.
	// It contains virtual functions that will be exectued automatically as long as the constructor is called
	class HPR_API EventHandler {
	private:
		GLFWwindow* window;

	protected:
		Hyperion graphics;

	public:
		EventHandler(
			const char* windowName,
			int width,
			int height,
			bool& succ
		);
		~EventHandler();

		KeyState getKeyState(KeyCode key);

		void update();

		// Overridable
		void virtual onUpdate();
		void virtual onKeyPress(KeyCode key, KeyState state);
		void virtual onTerminate();
	};

	EventHandler& windowToHandler(GLFWwindow* window);
}

void keyPress(GLFWwindow* window, int key, int scancode, int action, int mods);