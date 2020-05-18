#pragma once
#include "api.h"
#include <string>

namespace Hyperion {
	/// <summary>
	/// Represents a pair of fragment and vertex shaders. The class compiles them and allows access to them.
	/// </summary>
	class HPR_API Shader {
	private:
		/// <summary>
		/// Checks errors in the compilation of the shaders.
		/// </summary>
		/// <param name="shader">The shader.</param>
		/// <param name="pname">The pname, for instance GL_COMPILE_STATUS.</param>
		void checkErr(const unsigned int shader, const unsigned int pname);

		/// <summary>
		/// Reads an entire file.
		/// </summary>
		/// <param name="fpath">The path to the file.</param>
		/// <param name="file">The contents of the file. This is returned.</param>
		void readEntireFile(const char* fpath, std::string& file);

		/// <summary>
		/// Creates the shader in openGL.
		/// </summary>
		/// <param name="fpath">The path of the file.</param>
		/// <param name="type">The type of shader.</param>
		/// <returns></returns>
		unsigned int createShader(const char* fpath, const unsigned int type);

		/// <summary>
		/// The ID of the shader in openGL.
		/// </summary>
		unsigned int shader = 0;		
		
		/// <summary>
		/// the current uniform index. When a new uniform is created this is its index.
		/// </summary>
		static unsigned int uniformIndex;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Shader"/> class.
		/// </summary>
		/// <param name="vert">The contents of the vertex shader.</param>
		/// <param name="frag">The contents of the fragment shader.</param>
		Shader(const char* vert, const char* frag);

		/// <summary>
		/// Adds a new uniform to the shader.
		/// </summary>
		/// <param name="name">The name of the uniform.</param>
		/// <param name="size">The size of the uniform.</param>
		/// <param name="usage">The usage symbol, required by OpenGL.</param>
		/// <returns>The ID of the newly created uniform.</returns>
		unsigned int addUniform(const char* name, unsigned int size, unsigned int usage);

		/// <summary>
		/// Updates a uniform in a shader.
		/// </summary>
		/// <param name="shader">The shader where the uniform lives.</param>
		/// <param name="block">The uniform block.</param>
		/// <param name="data">The new data of the shader.</param>
		/// <param name="size">The size of the shader.</param>
		static void updateUniform(unsigned int shader, unsigned int block, const void* data, unsigned int size);

		/// <summary>
		/// Updates a section of a uniform in a shader.
		/// </summary>
		/// <param name="shader">The shader where the uniform lives.</param>
		/// <param name="block">The uniform block.</param>
		/// <param name="data">The new data of that section of the uniform.</param>
		/// <param name="offset">The offset to the start of the section.</param>
		/// <param name="size">The size of the section.</param>
		static void updateUniformRange(unsigned int shader, unsigned int block, const void* data, unsigned int offset, unsigned int size);

		/// <summary>
		/// Gets the ID of the shader.
		/// </summary>
		/// <returns>The ID of the shader</returns>
		unsigned int getShader();
	};
}
