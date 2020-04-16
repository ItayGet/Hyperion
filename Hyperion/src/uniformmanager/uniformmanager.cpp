#include "uniformmanager.h"
#include "GL/glew.h"

namespace Hyperion {
	UniformManager::UniformManager(Shader& shader) {
		uniforms
			= {
			{
				UniformType::Camera, { Transformation(glm::mat4(1.)), "camera", 0, GL_STATIC_DRAW }
			},
			{
				UniformType::Resolution, { glm::vec2(), "resolution", 0, GL_STREAM_DRAW }
			},
		};

		for (auto it = uniforms.begin(); it != uniforms.end(); ++it) {
			auto& uni = it->second;
			uni.block = shader.addUniform(uni.str.c_str(), uni.value.getSize(), uni.usage);
			Shader::updateUniform(shader.getShader(), uni.block, boost::unsafe_any_cast<void*>(&uni.value), uni.value.getSize());

		}

		this->shader = shader.getShader();
	}
}