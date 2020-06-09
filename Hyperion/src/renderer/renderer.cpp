#include "renderer.h"
#include <iostream>

#define VERTEX_FILE_PATH "shaders/example.vert"
#define FRAGMENT_FILE_PATH "shaders/example.frag"

namespace Hyperion {

	Renderer::Renderer(GLFWwindow* window, ShapeData* shapes) : window(window), shader(VERTEX_FILE_PATH, FRAGMENT_FILE_PATH) {
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
		shader = { VERTEX_FILE_PATH, FRAGMENT_FILE_PATH };

		setShapeData(shapes);

		shapesBlock = shader.addUniform("shape", sizeof(*shapeData), GL_DYNAMIC_DRAW);
		cameraBlock = shader.addUniform("camera", sizeof(glm::mat4), GL_DYNAMIC_DRAW);

		glUseProgram(shader.getShader());

		// Handling vertex buffer objects and element buffer objects
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

	Shader& Renderer::getShader() {
		return shader;
	}

	bool Renderer::update(std::vector<unsigned int>& indexesToUpdate, const Transformation* transformations, const Transformation& cameraTransformation) {
		if (exit) {
			terminate();
			return false;
		}

		// Draw triangles
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Poll Events
		glfwPollEvents();
		
		for (int i = 0; i < indexesToUpdate.size(); i++) {
			int index = indexesToUpdate[i];

			// Update matrices
			transformations[index].toMatrix((glm::mat4&)shapeData->shapes[index].getTransform());

			// Update uniforms
			Shader::updateUniformRange(
				shader.getShader(),
				shapesBlock,
				&(shapeData->shapes[i]),
				(unsigned int)(index) * sizeof(Shape),
				sizeof(Shape)
			);

		}
		Shader::updateUniformRange(
			shader.getShader(),
			shapesBlock,
			&(shapeData->size),
			(unsigned int)&(((ShapeData*)nullptr)->size),
			sizeof(unsigned int)
		);

		glm::mat4 cameraMat;
		cameraTransformation.toMatrixCamera(cameraMat);
		Shader::updateUniform(
			shader.getShader(),
			cameraBlock,
			&cameraMat,
			sizeof(glm::mat4)
		);

		// Swap buffers
		glfwSwapBuffers(window);

		return true;
	}

	void Renderer::terminate() {
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
		glDeleteVertexArrays(1, &vao);
		glUseProgram(0);
		glDeleteProgram(shader.getShader());
	}

	Renderer::~Renderer() {
		terminate();
	}
}