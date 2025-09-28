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
	if (mp_vertexShader)
	{
		glDetachShader(m_id, mp_vertexShader->get());
		checkGLError();
	}
	if (mp_fragmentShader)
	{
		glDetachShader(m_id, mp_fragmentShader->get());
		checkGLError();
	}
	glDeleteProgram(m_id);
	checkGLError();
}

//------------------------------------------------------------------//
void ShaderProgram::setVertexShader(const std::string& path)
{
	if (mp_vertexShader)
	{
		mp_vertexShader->setShader(path, GL_VERTEX_SHADER);
	}
	else
	{
		mp_vertexShader = std::make_unique<Shader>(m_id, path, GL_VERTEX_SHADER);
		glAttachShader(m_id, mp_vertexShader->get());
		checkGLError();
		glLinkProgram(m_id);
		checkGLError();
	}
}

//------------------------------------------------------------------//

void ShaderProgram::setFragmentShader(const std::string& path)
{
	if (mp_fragmentShader)
	{
		mp_fragmentShader->setShader(path, GL_FRAGMENT_SHADER);
	}
	else
	{
		mp_fragmentShader = std::make_unique<Shader>(m_id, path, GL_FRAGMENT_SHADER);
		glAttachShader(m_id, mp_fragmentShader->get());
		checkGLError();
		glLinkProgram(m_id);
		checkGLError();
	}
}

//------------------------------------------------------------------//