#include <shaders/shader.h>
#include <utilities/file_io.h>
#include <ogl/gl_error.h>

#include <glm/gtc/type_ptr.hpp>

//------------------------------------------------------------------//

Shader::Shader(uint32_t shaderProgram, const std::string& path, GLenum shaderType)
		: m_shaderProgram(shaderProgram)
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
	// glDeleteShader(m_id);
}

//------------------------------------------------------------------//

void Shader::setBool(const std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), static_cast<int>(value));
	checkGLError();
}

//------------------------------------------------------------------//

void Shader::setInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
	checkGLError();
}

//------------------------------------------------------------------//

void Shader::setFloat(const std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
	checkGLError();
}

//------------------------------------------------------------------//

void Shader::setMat4(const std::string& name, glm::mat4 value)
{
	glUseProgram(m_shaderProgram);
	checkGLError();
	glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	checkGLError();
}

//------------------------------------------------------------------//
