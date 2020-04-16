#pragma once
#include "api.h"
#include "glm/glm.hpp"
#include "sizeany/sizedany.h"
#include "shader/shader.h"
#include "gameobject/gameobject.h"
#include <unordered_map>
#include <variant>

#include <iostream>

namespace Hyperion {
	struct HPR_API BadUniformAccess : public std::exception {
		virtual const char* what() const noexcept override {
			return "bad uniform access";
		}
	};

	struct Uniform {

		SizedAny value;
		std::string str;
		unsigned int block;
		unsigned int usage;
	};

	enum class UniformType {
		Resolution,
		Camera,
		Test,
	};

	class HPR_API UniformManager {
	private:

		std::unordered_map<UniformType, Uniform> uniforms;
		unsigned int shader;

	public:

		UniformManager(Shader& shader);

		template<typename T>
		T getUniform(UniformType type) {
			auto& any = uniforms[type].value;
			if (any.type() != typeid(T)) {
				throw BadUniformAccess{};
			}

			return boost::any_cast<T>(any);
		}

		template<typename T>
		void setUniform(UniformType type, const T& val) {
			auto& uni = uniforms[type];
			if (uni.value.type() != typeid(T)) {
				throw BadUniformAccess{};
			}

			uni.value = val;

			Shader::updateUniform(shader, uni.block, &val, sizeof(val));
		}
	};
}