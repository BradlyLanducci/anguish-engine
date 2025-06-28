#include "vao.h"
#include "../utilities/gl_error.h"

#include <glad/glad.h>

//------------------------------------------------------------------//

VAO::VAO()
{
	glGenVertexArrays(1, &m_id);
	checkGLError();
	glBindVertexArray(m_id);
	checkGLError();
}

//------------------------------------------------------------------//

VAO::~VAO()
{
}

//------------------------------------------------------------------//
