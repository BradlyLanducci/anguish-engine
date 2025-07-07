#pragma once

//------------------------------------------------------------------//

#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <shaders/shader_program.h>
#include <physics/physics_object.h>

//------------------------------------------------------------------//

class Object2D : public PhysicsObject
{
public:
	Object2D();
	~Object2D();

	void draw() override;
	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;

private:
	float vertices[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
};

//------------------------------------------------------------------//