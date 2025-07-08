#pragma once

//------------------------------------------------------------------//

#include <utilities/data_structures.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <shaders/shader_program.h>

#include <glm/glm.hpp>

//------------------------------------------------------------------//

class Object
{
public:
	virtual ~Object() = default;
	virtual void idleUpdate(float delta) = 0;

protected:
	Vector2 m_globalPosition;
};

//------------------------------------------------------------------//