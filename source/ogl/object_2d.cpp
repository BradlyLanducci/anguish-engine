#include <ogl/object_2d.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>
#include <ogl/gl_error.h>

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

Object2D::Object2D()
{
	shaderProgram.setVertexShader("source/shaders/vert.glsl");
	shaderProgram.setFragmentShader("source/shaders/frag.glsl");

	std::shared_ptr<Object2D> obj = std::shared_ptr<Object2D>(this);
	IdleManager::get().addObject(obj);
	PhysicsManager::get().addObject(obj);
}

//------------------------------------------------------------------//

Object2D::~Object2D()
{
	LOG(INFO) << "Destroyed object";
}

//------------------------------------------------------------------//

void Object2D::draw()
{
	updateMatrices();

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
	glBindVertexArray(getVao());
	checkGLError();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	checkGLError();
}

//------------------------------------------------------------------//

void Object2D::idleUpdate(float delta)
{
	m_model = glm::translate(glm::mat4(1.0f), glm::vec3(m_globalPosition.x, -m_globalPosition.y, 0.f));
	draw();
}

//------------------------------------------------------------------//

void Object2D::physicsUpdate(float delta)
{
	m_globalPosition.y += 0.6f * delta;
}

//------------------------------------------------------------------//
