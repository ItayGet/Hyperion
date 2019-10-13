#include "shader.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <fstream>
#include <string>
#include <sstream>

namespace Hyperion {
	Shader::Shader(const char* vert, const char* frag) {
		unsigned int vertexShader = createShader(vert, GL_VERTEX_SHADER);
		unsigned int fragmentShader = createShader(frag, GL_FRAGMENT_SHADER);

		shader = glCreateProgram();

		glAttachShader(shader, vertexShader);
		glAttachShader(shader, fragmentShader);
		glLinkProgram(shader);

		checkErr(shader, GL_LINK_STATUS);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	unsigned int Shader::GetShader() {
		return shader;
	}

	unsigned int Shader::createShader(const char* fpath, const unsigned int type) {
		std::string filestr;
		readEntireFile(fpath, filestr);
		const char* file = filestr.c_str();
		unsigned int shader = glCreateShader(type);
		glShaderSource(shader, 1, &file, 0);
		glCompileShader(shader);
		return shader;
	}

	void Shader::checkErr(const unsigned int shader, const unsigned int pname) {
		int  success;
		char infoLog[512];
		glGetShaderiv(shader, pname, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	void Shader::readEntireFile(const char* fpath, std::string& file) {
		std::ifstream t;
		t.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		t.open(fpath);
		std::stringstream stream;
		stream << t.rdbuf();
		file = stream.str();
	}
}