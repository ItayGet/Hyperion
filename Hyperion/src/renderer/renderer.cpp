#include "renderer.h"
#include "shader/shader.h"

#define VERTEX_FILE_PATH "shaders/example.vert"
#define FRAGMENT_FILE_PATH "shaders/example.frag"

namespace Hyperion {
	//Renderer::Shape::Shape(glm::vec3 pos, float radius, glm::vec3 color) {
	//	this->pos = pos;
	//	this->radius = radius;
	//	this->color = color;
	//}

	Renderer::Renderer(GLFWwindow* window) : window(window) {
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

		shapeData =
		{
			{
				glm::vec3(0.5, 0., -5.), 1., glm::vec3(1., 0., 0.), 0.,
				glm::vec3(0. , 0., -5), 1.2, glm::vec3(1., 1., 1.), 0.,
				glm::vec3(-0.5, 0., -5), 1., glm::vec3(0., 0., 1.), 0.,
			},
			3
		};

		shapesBlock = shader.addUniform("shape", sizeof(shapeData), GL_DYNAMIC_DRAW);

		shaderProg = shader.getShader();
		Shader::updateUniform(shaderProg, shapesBlock, &shapeData, sizeof(shapeData));
		glUseProgram(shaderProg);

		//Handling vertex buffer objeccts and element buffer objects
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

	bool Renderer::Update() {
		if (exit) {
			terminate();
			return false;
		}


		//double counter = glfwGetTime();
		//counter = counter > 5. ? counter - 5. : 0.;
		//shapeData.shapes[0].pos = glm::vec3(0.5 - counter/4, 0., -5);
		//Shader::updateUniform(shader, shapesBlock, &shapeData, sizeof(shapeData));

		glClearColor(.0f, .0f, .0f, .0f);
		glClear(GL_COLOR_BUFFER_BIT);

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