#include <texture/texture.h>
#include <ogl/gl_error.h>
#include <shaders/shader.h>

#include <glad/glad.h>

//------------------------------------------------------------------//

Texture::Texture()
{
	m_shaderProgram.setVertexShader("source/shaders/vert.glsl");
	m_shaderProgram.setFragmentShader("source/shaders/frag.glsl");
	setSize(Vector2());
}

//------------------------------------------------------------------//

Texture::~Texture()
{
}

//------------------------------------------------------------------//

uint32_t Texture::getVao() const
{
	return m_vao.get();
}

//------------------------------------------------------------------//

uint32_t Texture::getVbo() const
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

uint32_t& Texture::getVbo()
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

Vector2 Texture::get_size() const
{
	return m_size;
}

//------------------------------------------------------------------//

void Texture::setSize(Vector2 size)
{
	m_size = size;

	const float x = 515.f;
	const float y = 515.f;
	const float z = 0.f;
	const float width = 50.f;
	const float height = 50.f;

	// clang-format off
	m_vertices = {
		// bl, tr, tl  -- triangle 1
		x, y, z, 
		x + width, y, z, 
		x + width, y + height, z,
		
		// bl, tr, tl  -- triangle 2
		x, y, z, 
		x + width, y + height, z, 
		x, y + height, z};
	// clang-format on
}

//------------------------------------------------------------------//

const std::array<float, NUM_VERTICES>& Texture::getVertices()
{
	return m_vertices;
}

//------------------------------------------------------------------//

void Texture::setProjectionMatrix(glm::mat4 projection)
{
	m_shaderProgram.m_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void Texture::draw()
{
	updateMatrices();

	glUseProgram(m_shaderProgram.get());
	checkGLError();
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo.get());
	checkGLError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices.data(), GL_STATIC_DRAW);
	checkGLError();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	checkGLError();
	glEnableVertexAttribArray(0);
	checkGLError();
	glBindVertexArray(getVao());
	checkGLError();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	checkGLError();
}

//------------------------------------------------------------------//

void Texture::updateMatrices()
{
	m_shaderProgram.m_vertexShader->setMat4("model", m_model);
	m_shaderProgram.m_vertexShader->setMat4("view", m_view);
}

//------------------------------------------------------------------//
