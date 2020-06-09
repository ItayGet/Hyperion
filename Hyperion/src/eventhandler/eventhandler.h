#pragma once
#include "api.h"
#include "hyperion/hyperion.h"
#include "keyprops/keycode.h"
#include "keyprops/keystate.h"

namespace Hyperion {
	/// <summary>
	/// The main class of the library. It allows users to handle events and it should be inherited.
	/// </summary>
	/// <remark>
	/// <para>
	/// It contains virtual functions that will be exectued automatically as long as the constructor is called.
	/// </para>
	/// <para>
	/// The class also creates a window, which is controlled using <see cref="graphics"/>.
	/// </para>
	/// <para>
	/// In addition, it lets the programmer access to input from the user.
	/// </para>
	/// </remark>
	class HPR_API EventHandler {
	private:
		GLFWwindow* window;

	protected:
		/// <summary>
		/// This object is how you control the contents of the window.
		/// See <see cref="Hyperion"/> for more information.
		/// </summary>
		Hyperion graphics;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="EventHandler"/> class.
		/// </summary>
		/// <param name="windowName">Name of the window.</param>
		/// <param name="width">The width of the window.</param>
		/// <param name="height">The height of the window.</param>
		/// <param name="succ">Whether initialization suceeded.</param>
		EventHandler(
			const char* windowName,
			int width,
			int height,
			bool& succ
		);
		~EventHandler();

		/// <summary>
		/// Gets the mouse position.
		/// </summary>
		/// <param name="pos">The position of the mouse currently.</param>
		void getMousePos(glm::dvec2& pos);

		/// <summary>
		/// Get the state of a certain key.
		/// </summary>
		/// <param name="key">The key queried.</param>
		/// <returns>The state of the key queried.</returns>
		KeyState getKeyState(KeyCode key);

		/// <summary>
		/// This function needs to be called in <c>main</c> in order to run the library.
		/// </summary>
		void start();

		/// <summary>
		/// This function needs to be overriden and is called every frame.
		/// </summary>
		void virtual onUpdate();

		/// <summary>
		/// This function needs to be overriden and is on called key press.
		/// </summary>
		/// <param name="key">The key that was pressed.</param>
		/// <param name="state">The state of the key.</param>
		void virtual onKeyPress(KeyCode key, KeyState state);

		/// <summary>
		/// This function needs to be overriden and is called every time the mouse moves.
		/// </summary>
		/// <param name="pos">The new position of the mouse.</param>
		void virtual onMouseMove(glm::dvec2 pos);

		/// <summary>
		/// This function needs to be overriden and is called on exit.
		/// </summary>
		void virtual onTerminate();
	};

	EventHandler& windowToHandler(GLFWwindow* window);
}

void keyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouseMove(GLFWwindow* window, double xpos, double ypos);