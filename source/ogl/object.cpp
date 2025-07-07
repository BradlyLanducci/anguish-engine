#include <ogl/object.h>
#include <shaders/shader.h>

#include <glad/glad.h>

//------------------------------------------------------------------//

uint32_t Object::getVao() const
{
	return m_vao.get();
}

//------------------------------------------------------------------//

uint32_t Object::getVbo() const
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

uint32_t& Object::getVbo()
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

void Object::updateMatrices()
{
	shaderProgram.m_vertexShader->setMat4("model", m_model);
	shaderProgram.m_vertexShader->setMat4("view", m_view);
	shaderProgram.m_vertexShader->setMat4("projection", m_projection);
}

//------------------------------------------------------------------//
