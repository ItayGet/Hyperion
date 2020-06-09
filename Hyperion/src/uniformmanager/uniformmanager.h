#pragma once
#include "api.h"
#include "glm/glm.hpp"
#include "sizedany/sizedany.h"
#include "shader/shader.h"
#include "gameobject/gameobject.h"
#include <unordered_map>
#include <variant>

#include <iostream>

namespace Hyperion {
	/// <summary>
	/// Called on <see cref="UniformManager::getUniform"/> and <see cref="UniformManager::setUniform"/>.
	/// </summary>
	struct HPR_API BadUniformAccess : public std::exception {		
		virtual const char* what() const noexcept override {
			return "bad uniform access";
		}
	};

	/// <summary>
	/// Reprensents a uniform by the memory itself.
	/// </summary>
	struct HPR_API Uniform {

		/// <summary>
		/// The value on the CPU.
		/// </summary>
		SizedAny value;

		/// <summary>
		/// String to insert into the shader.
		/// </summary>
		std::string str;

		/// <summary>
		/// The block of the current uniform.
		/// </summary>
		unsigned int block;

		/// <summary>
		/// The usage symbol, required by OpenGL.
		/// </summary>
		unsigned int usage;
	};

	/// <summary>
	/// An enum for the different kinds of uniforms available.
	/// </summary>
	enum class HPR_API UniformType {
		/// <summary>
		/// The resolution of the window.
		/// </summary>
		Resolution,
	};

	/// <summary>
	/// Controls window's properties and other details that don't justify a whole system.
	/// To see the different kinds of uniforms available, see <see cref="UniformType"/>.
	/// </summary>
	class HPR_API UniformManager {
	private:

		/// <summary>
		/// Maps the types of uniforms to the uniform memory.
		/// Every value on the <see cref="Uniform"/> struct is assigned to the type wanted and is then never changed.
		/// </summary>
		std::unordered_map<UniformType, Uniform> uniforms;

		/// <summary>
		/// A reference to the shapes' shader.
		/// </summary>
		unsigned int shader;

	public:

		/// <summary>
		/// Initializes a new instance of the <see cref="UniformManager"/> class.
		/// </summary>
		/// <param name="shader">The shapes' shader</param>
		UniformManager(Shader& shader);

		/// <summary>
		/// Gets a uniform.
		/// </summary>
		/// <param name="type">The type of uniform. </param>
		/// <returns>The uniform.</returns>
		/// <exception cref = "BadUniformAccess">Thrown when <paramref name="type"/> does not match the type of the return type.</exception>
		template<typename T>
		T getUniform(UniformType type) {
			auto& any = uniforms[type].value;
			if (any.type() != typeid(T)) {
				throw BadUniformAccess{};
			}

			return boost::any_cast<T>(any);
		}

		/// <summary>
		/// Sets a uniform.
		/// </summary>
		/// <param name="type">The type.</param>
		/// <param name="val">The value.</param>
		/// <exception cref = "BadUniformAccess">Thrown when <paramref name="type"/> does not match the type of <paramref name="val"/>.</exception>
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