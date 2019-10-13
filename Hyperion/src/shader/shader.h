#pragma once
#include "api.h"
#include <string>

namespace Hyperion {
	class HPR_API Shader {
	private:
		void checkErr(const unsigned int shader, const unsigned int pname);
		void readEntireFile(const char* fpath, std::string& file);
		unsigned int createShader(const char* fpath, const unsigned int type);
		unsigned int shader = 0;
	public:
		Shader(const char* vert, const char* frag);
		unsigned int GetShader();
	};
}