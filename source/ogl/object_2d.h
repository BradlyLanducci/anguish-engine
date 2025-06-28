#pragma once

//------------------------------------------------------------------//

#include "vao.h"
#include "vbo.h"
#include "../shaders/shader_program.h"

//------------------------------------------------------------------//

class Object2D
{
public:
	Object2D();
	~Object2D() = default;

	uint32_t get_vao() const;
	uint32_t get_vbo() const;
	uint32_t& get_vbo();

	void draw();

private:
	VAO m_vao;
	VBO m_vbo;

	ShaderProgram shaderProgram;

	float vertices[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
};

//------------------------------------------------------------------//