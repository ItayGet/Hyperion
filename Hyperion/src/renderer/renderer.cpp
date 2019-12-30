#include "renderer.h"
#include "shader/shader.h"
#include <iostream>

#define VERTEX_FILE_PATH "shaders/example.vert"
#define FRAGMENT_FILE_PATH "shaders/example.frag"

namespace Hyperion {

	Renderer::Renderer(GLFWwindow* window, ShapeData* shapes) : window(window) {
		//Setting up vertices
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

		//Shader stuff
		Shader shader(VERTEX_FILE_PATH, FRAGMENT_FILE_PATH);

		setShapeData(shapes);

		shapesBlock = shader.addUniform("shape", sizeof(*shapeData), GL_DYNAMIC_DRAW);

		shaderProg = shader.getShader();
		//Shader::updateUniform(shaderProg, shapesBlock, shapeData, sizeof(*shapeData));
		glUseProgram(shaderProg);

		//Handling vertex buffer objects and element buffer objects
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
	}

	void Renderer::setShapeData(ShapeData* shapeData) {
		this->shapeData = shapeData;
	}

	bool Renderer::update(std::vector<unsigned int>& indexesToUpdate) {
		if (exit) {
			terminate();
			return false;
		}

		//Draw triangles
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		//Update uniforms
		for (int i = 0; i < indexesToUpdate.size(); i++) {
			Shader::updateUniformRange(
				shader, 
				shapesBlock,
				&(shapeData->shapes[i]),
				(unsigned int)(indexesToUpdate[i]) * sizeof(Shape),
				sizeof(Shape)
			);

		}
		Shader::updateUniformRange(
			shader,
			shapesBlock,
			&(shapeData->size),
			(unsigned int)&(((ShapeData*)nullptr)->size),
			sizeof(unsigned int)
		);

		//Swap buffers
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