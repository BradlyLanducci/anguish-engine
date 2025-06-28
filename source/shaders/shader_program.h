#pragma once

//------------------------------------------------------------------//

#include <string>
#include <memory>

//------------------------------------------------------------------//

class Shader;

//------------------------------------------------------------------//

class ShaderProgram
{
public:
	/// @brief Creates a shader program. Internally holds a single vertex and fragment shader at one time
	ShaderProgram();
	~ShaderProgram();

	void setVertexShader(const std::string& path);
	void setFragmentShader(const std::string& path);

	/// @brief Gets the shader program ID
	/// @return
	uint32_t get() const;

private:
	uint32_t m_id{0};

	std::unique_ptr<Shader> m_vertexShader{nullptr};
	std::unique_ptr<Shader> m_fragmentShader{nullptr};
};

//------------------------------------------------------------------//
