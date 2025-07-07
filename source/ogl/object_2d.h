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
	float vertices[18] = {
			// First triangle
			100.0f, 100.0f, 0.0f, // Bottom-left
			300.0f, 100.0f, 0.0f, // Bottom-right
			300.0f, 250.0f, 0.0f, // Top-right

			// Second triangle
			100.0f, 100.0f, 0.0f, // Bottom-left
			300.0f, 250.0f, 0.0f, // Top-right
			100.0f, 250.0f, 0.0f	// Top-left
	};
};

//------------------------------------------------------------------//