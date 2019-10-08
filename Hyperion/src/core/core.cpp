#include "core.h"
#include <string>

#define VERTEX_FILE_PATH "shaders\\example.vert"
#define FRAGMENT_FILE_PATH "shaders\\example.frag"

namespace Hyperion {
	void HPRCore::checkErr(const unsigned int shader, const unsigned int pname) {
		int  success;
		char infoLog[512];
		glGetShaderiv(shader, pname, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	std::string HPRCore::readEntireFile(const char* fpath) {
		std::ifstream t(fpath);
		std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());
		return str;
	}

	unsigned int HPRCore::createShader(const char* fpath, const unsigned int type) {
		unsigned int shader = glCreateShader(type);
		glShaderSource(shader, 1, &fpath, NULL);
		glCompileShader(shader);

		checkErr(shader, GL_COMPILE_STATUS);

		return shader;
	}

	void HPRCore::terminate() {
		exit = true;
	}

	void HPRCore::createShaderProgram() {
		unsigned int shader = glCreateProgram();

		unsigned int vertexShader = createShader(VERTEX_FILE_PATH, GL_VERTEX_SHADER);
		unsigned int fragmentShader = createShader(FRAGMENT_FILE_PATH, GL_FRAGMENT_SHADER);

		glAttachShader(shader, vertexShader);
		glAttachShader(shader, fragmentShader);
		glLinkProgram(shader);

		checkErr(shader, GL_LINK_STATUS);
		
		glUseProgram(shader);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void HPRCore::Init() {

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		if (!glfwInit())
			glfwTerminate();
			terminate();

		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			terminate();
		}

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			terminate();

	}

	bool HPRCore::Update() {
		if (glfwWindowShouldClose(window) ||
			exit
			) {
			return false;
		}

		glClearColor(color, .3f, .5f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(window);
		glfwPollEvents();

		return true;
	}
}