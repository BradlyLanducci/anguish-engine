#include <texture/sprite.h>
#include <renderer/rendering_manager.h>
#include <idle/idle_manager.h>
#include <utilities/keyboard.h>
#include <physics/physics_manager.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>
#include <ogl/vertices.h>

//------------------------------------------------------------------//

Sprite::Sprite()
{
	std::shared_ptr<Sprite> sprite = std::shared_ptr<Sprite>(this);
	IdleManager::addObject(sprite);
	PhysicsManager::addObject(sprite);
	RenderingManager::addObject(sprite);

	m_shaderProgram.setVertexShader("source/shaders/vert.glsl");
	m_shaderProgram.setFragmentShader("source/shaders/frag.glsl");

	glUseProgram(m_shaderProgram.get());
	checkGLError();
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo.get());
	checkGLError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(QUAD_VERTICES), QUAD_VERTICES, GL_STATIC_DRAW);
	checkGLError();
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	checkGLError();
	glEnableVertexAttribArray(0);
	checkGLError();
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	checkGLError();
	glEnableVertexAttribArray(1);
	checkGLError();
	glBindVertexArray(m_vao.get());
	checkGLError();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo.get());
	checkGLError();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(QUAD_INDICES), QUAD_INDICES, GL_STATIC_DRAW);
	checkGLError();

	m_shaderProgram.m_fragmentShader->setInt("texture1", 0);
}

//------------------------------------------------------------------//

void Sprite::setTexture(const std::string& texturePath)
{
	m_texture.load(texturePath);
}

//------------------------------------------------------------------//

void Sprite::setProjectionMatrix(glm::mat4 projection)
{
	m_shaderProgram.m_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void Sprite::draw()
{
	m_shaderProgram.m_vertexShader->setMat4("model", m_model);
	m_shaderProgram.m_vertexShader->setMat4("view", m_view);
	m_shaderProgram.m_vertexShader->setVec2("globalPos", m_globalPosition);
	m_shaderProgram.m_vertexShader->setVec2i("spriteSize", m_texture.getSize() * m_scale);
	glUseProgram(m_shaderProgram.get());
	glBindVertexArray(m_vao.get());
	m_texture.bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	checkGLError();
}

//------------------------------------------------------------------//

void Sprite::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Sprite::physicsUpdate(float delta)
{
	float amountToMove = 60.f * delta;
	if (Keyboard::isPressed(263)) // left
	{
		m_globalPosition.x -= amountToMove;
	}
	if (Keyboard::isPressed(265)) // up
	{
		m_globalPosition.y -= amountToMove;
	}
	if (Keyboard::isPressed(262)) // right
	{
		m_globalPosition.x += amountToMove;
	}
	if (Keyboard::isPressed(264)) // down
	{
		m_globalPosition.y += amountToMove;
	}
}

//------------------------------------------------------------------//
