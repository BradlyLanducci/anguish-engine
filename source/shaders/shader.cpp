#include "shader.h"
#include "../utilities/file_io.h"
#include "../utilities/gl_error.h"

//------------------------------------------------------------------//

Shader::Shader(const std::string& path, GLenum shaderType)
{
	setShader(path, shaderType);
}

//------------------------------------------------------------------//

Shader::~Shader()
{
	if (m_id > 0)
	{
		glDeleteShader(m_id);
		checkGLError();
	}
}

//------------------------------------------------------------------//

void Shader::setShader(const std::string& path, GLenum shaderType)
{
	if (m_id > 0)
	{
		glDeleteShader(m_id);
	}
	const std::string str = FileIO::toString(path);
	const char* source = str.c_str();
	m_id = glCreateShader(shaderType);
	checkGLError();
	glShaderSource(m_id, 1, &source, NULL);
	checkGLError();
	glCompileShader(m_id);
	checkGLError();
}

//------------------------------------------------------------------//
