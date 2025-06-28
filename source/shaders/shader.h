#pragma once

//------------------------------------------------------------------//

#include <string>

#include <glad/glad.h>

//------------------------------------------------------------------//

class Shader
{
public:
	/// @brief Creates a shader from a provided file path
	/// @param path
	Shader(const std::string& path, GLenum shaderType);
	~Shader();

	/// @brief Returns shader ID
	/// @return
	uint32_t get() const;

	/// @brief Sets and compiles new shader
	/// @param path
	void setShader(const std::string& path, GLenum shaderType);

private:
	uint32_t m_id{0};
};

//------------------------------------------------------------------//
