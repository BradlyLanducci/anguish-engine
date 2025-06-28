#include "shader_program.h"
#include "shader.h"
#include "../utilities/gl_error.h"

#include <glad/glad.h>

//------------------------------------------------------------------//

ShaderProgram::ShaderProgram()
{
	m_id = glCreateProgram();
}

//------------------------------------------------------------------//

ShaderProgram::~ShaderProgram()
{
	if (m_vertexShader)
	{
		glDetachShader(m_id, m_vertexShader->get());
	}
	if (m_fragmentShader)
	{
		glDetachShader(m_id, m_fragmentShader->get());
	}
	glDeleteProgram(m_id);
}

//------------------------------------------------------------------//
void ShaderProgram::setVertexShader(const std::string& path)
{
	if (m_vertexShader)
	{
		m_vertexShader->setShader(path, GL_VERTEX_SHADER);
	}
	else
	{
		m_vertexShader = std::make_unique<Shader>(path, GL_VERTEX_SHADER);
		glAttachShader(m_id, m_vertexShader->get());
		glLinkProgram(m_id);
	}
}

//------------------------------------------------------------------//

void ShaderProgram::setFragmentShader(const std::string& path)
{
	if (m_fragmentShader)
	{
		m_fragmentShader->setShader(path, GL_FRAGMENT_SHADER);
	}
	else
	{
		m_fragmentShader = std::make_unique<Shader>(path, GL_FRAGMENT_SHADER);
		glAttachShader(m_id, m_fragmentShader->get());
		glLinkProgram(m_id);
	}
}

//------------------------------------------------------------------//

uint32_t ShaderProgram::get() const
{
	return m_id;
}

//------------------------------------------------------------------//