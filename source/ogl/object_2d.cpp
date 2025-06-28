#include "object_2d.h"
#include "../utilities/gl_error.h"

#include <glad/glad.h>

//------------------------------------------------------------------//

Object2D::Object2D()
{
	shaderProgram.setVertexShader("source/shaders/vert.vs");
	shaderProgram.setFragmentShader("source/shaders/frag.fs");
}

//------------------------------------------------------------------//

uint32_t Object2D::get_vao() const
{
	return m_vao.get();
}

//------------------------------------------------------------------//

uint32_t Object2D::get_vbo() const
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

uint32_t& Object2D::get_vbo()
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

void Object2D::draw()
{
	glUseProgram(shaderProgram.get());
	checkGLError();

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo.get());
	checkGLError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	checkGLError();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	checkGLError();
	glEnableVertexAttribArray(0);
	checkGLError();
	glBindVertexArray(get_vao());
	checkGLError();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	checkGLError();
}

//------------------------------------------------------------------//
