#include <texture/sprite.h>
#include <renderer/rendering_manager.h>
#include <idle/idle_manager.h>
#include <utilities/keyboard.h>
#include <physics/physics_manager.h>
#include <shaders/shader.h>
#include <ogl/gl_error.h>

//------------------------------------------------------------------//

Sprite::Sprite()
{
	std::shared_ptr<Sprite> sprite = std::shared_ptr<Sprite>(this);
	IdleManager::addObject(sprite);
	PhysicsManager::addObject(sprite);
	RenderingManager::addObject(sprite);

	m_shaderProgram.setVertexShader("source/shaders/vert.glsl");
	m_shaderProgram.setFragmentShader("source/shaders/frag.glsl");

	setTexture("assets/textures/sprite.png");
}

//------------------------------------------------------------------//

uint32_t Sprite::getVao() const
{
	return m_vao.get();
}

//------------------------------------------------------------------//

uint32_t Sprite::getVbo() const
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

uint32_t& Sprite::getVbo()
{
	return m_vbo.get();
}

//------------------------------------------------------------------//

void Sprite::setTexture(const std::string& texturePath)
{
	// m_texture = load(texturePath);
}

//------------------------------------------------------------------//

void Sprite::updateVertices()
{
	if (m_texture)
	{
		m_model = glm::translate(glm::mat4(1.0f), glm::vec3(m_globalPosition.x, m_globalPosition.y, 0.f));

		float x{m_globalPosition.x};
		float y{m_globalPosition.y};
		Vector2 size(50.f, 50.f); // = m_texture->get_size();

		// clang-format off
		m_vertices = {
			// bl, tr, tl  -- triangle 1
			x, y, 
			x + size.x, y, 
			x + size.x, y + size.y,
			
			// bl, tr, tl  -- triangle 2
			x, y, 
			x + size.x, y + size.y, 
			x, y + size.y
		};
		// clang-format on
	}
}

//------------------------------------------------------------------//

void Sprite::setProjectionMatrix(glm::mat4 projection)
{
	m_shaderProgram.m_vertexShader->setMat4("projection", projection);
}

//------------------------------------------------------------------//

void Sprite::draw()
{
	updateMatrices();
	updateVertices();

	glUseProgram(m_shaderProgram.get());
	checkGLError();
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo.get());
	checkGLError();
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices.data(), GL_STATIC_DRAW);
	checkGLError();
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	checkGLError();
	glEnableVertexAttribArray(0);
	checkGLError();
	glBindVertexArray(getVao());
	checkGLError();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	checkGLError();
}

//------------------------------------------------------------------//

void Sprite::updateMatrices()
{
	m_shaderProgram.m_vertexShader->setMat4("model", m_model);
	m_shaderProgram.m_vertexShader->setMat4("view", m_view);
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
