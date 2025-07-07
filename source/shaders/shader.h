#pragma once

//------------------------------------------------------------------//

#include "../ogl/gl_object.h"

#include <string>
#include <glad/glad.h>

#include <glm/glm.hpp>

//------------------------------------------------------------------//

class Shader : public GlObject
{
public:
	/// @brief Creates a shader from a provided file path
	/// @param path
	Shader(uint32_t shaderProgram, const std::string& path, GLenum shaderType);
	~Shader() override;

	/// @brief Sets and compiles new shader
	/// @param path
	void setShader(const std::string& path, GLenum shaderType);

	void setBool(const std::string& name, bool value);
	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void setMat4(const std::string& name, glm::mat4 value);

private:
	uint32_t m_shaderProgram{0};
};

//------------------------------------------------------------------//
