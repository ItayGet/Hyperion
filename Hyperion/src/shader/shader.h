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
		static unsigned int uniformIndex;
	public:
		Shader(const char* vert, const char* frag);
		unsigned int addUniform(const char* name, unsigned int size, unsigned int usage);
		static void updateUniform(unsigned int shader, unsigned int block, const void* data, unsigned int size);
		static void updateUniformRange(unsigned int shader, unsigned int block, const void* data, unsigned int offset, unsigned int size);
		unsigned int getShader();
	};
}
