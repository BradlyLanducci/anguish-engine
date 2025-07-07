#include <ogl/object_2d.h>
#include <ogl/gl_error.h>

#include <glad/glad.h>
#include "object_2d.h"

#include <physics/physics_manager.h>

//------------------------------------------------------------------//

Object2D::Object2D()
{
	shaderProgram.setVertexShader("source/shaders/vert.glsl");
	shaderProgram.setFragmentShader("source/shaders/frag.glsl");

	PhysicsManager::get().addObject(std::shared_ptr<Object2D>(this));
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

void Object2D::idleUpdate()
{
	LOG(INFO) << "Idle update";
}

//------------------------------------------------------------------//

void Object2D::physicsUpdate()
{
	LOG(INFO) << "Physics update";
}

//------------------------------------------------------------------//
