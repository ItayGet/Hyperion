#pragma once
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <fstream>
#include "../hyperion.h"
//#include <string>

#ifdef HPR_BUILD_DLL
#define HPR_API __declspec(dllexport)
#else
#define HPR_API __declspec(dllimport)
#endif

namespace Hyperion {
	class HPR_API HPRCore {
	private:
		GLFWwindow* window = NULL;
		bool exit = false;
		void checkErr(const unsigned int shader, const unsigned int pname);
		std::string readEntireFile(const char* fpath);
		unsigned int createShader(const char* fpath, const unsigned int type);
		void createShaderProgram();
		void terminate();
	public:
		float color = .0f;
		void Init();
		bool Update();
	};
}