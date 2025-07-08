#pragma once

//------------------------------------------------------------------//

#include <utilities/data_structures.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <shaders/shader_program.h>

#include <cstdint>
#include <array>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Texture
{
public:
	Texture() = default;
	~Texture() = default;

	Vector2 getSize() const;
	void setSize(Vector2 size);

protected:
	Vector2 m_size;
};

//------------------------------------------------------------------//
