#include <shaders/shader_program.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>

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
		checkGLError();
	}
	if (m_fragmentShader)
	{
		glDetachShader(m_id, m_fragmentShader->get());
		checkGLError();
	}
	glDeleteProgram(m_id);
	checkGLError();
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
		m_vertexShader = std::make_unique<Shader>(m_id, path, GL_VERTEX_SHADER);
		glAttachShader(m_id, m_vertexShader->get());
		checkGLError();
		glLinkProgram(m_id);
		checkGLError();
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
		m_fragmentShader = std::make_unique<Shader>(m_id, path, GL_FRAGMENT_SHADER);
		glAttachShader(m_id, m_fragmentShader->get());
		checkGLError();
		glLinkProgram(m_id);
		checkGLError();
	}
}

//------------------------------------------------------------------//