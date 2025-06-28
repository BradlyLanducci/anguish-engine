#pragma once

//------------------------------------------------------------------//

#include "../ogl/gl_object.h"

#include <string>
#include <glad/glad.h>

//------------------------------------------------------------------//

class Shader : public GlObject
{
public:
	/// @brief Creates a shader from a provided file path
	/// @param path
	Shader(const std::string& path, GLenum shaderType);
	~Shader() override;

	/// @brief Sets and compiles new shader
	/// @param path
	void setShader(const std::string& path, GLenum shaderType);
};

//------------------------------------------------------------------//
