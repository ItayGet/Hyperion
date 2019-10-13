#include "renderer.h"
#include "shader/shader.h"

#define VERTEX_FILE_PATH "shaders/example.vert"
#define FRAGMENT_FILE_PATH "shaders/example.frag"

namespace Hyperion {

	Renderer::Renderer(GLFWwindow* window) : window(window) {
		float vertices[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f
		};
		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3 
		};

		Shader shader(VERTEX_FILE_PATH, FRAGMENT_FILE_PATH);
		shaderProg = shader.getShader();
		glUseProgram(shaderProg);


		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);
		glGenVertexArrays(1, &vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindVertexArray(vao);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//unsigned int ubo;
		//glGenBuffers(1, &ubo);
		//glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		//glBufferData(GL_UNIFORM_BUFFER, );
	}

	bool Renderer::Update() {
		if (exit) {
			terminate();
			return false;
		}

		glClearColor(.0f, .0f, .0f, .0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//shader.use();
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();

		return true;
	}

	void Renderer::terminate() {
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
		glDeleteVertexArrays(1, &vao);
		glUseProgram(0);
		glDeleteProgram(shaderProg);
	}

	Renderer::~Renderer() {
		terminate();
	}
}