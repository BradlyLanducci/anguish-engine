#pragma once

//------------------------------------------------------------------//

#include "vao.h"
#include "vbo.h"
#include "../shaders/shader_program.h"
#include "../utilities/data_structures.h"

#include <glm/glm.hpp>

//------------------------------------------------------------------//

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	uint32_t getVao() const;
	uint32_t getVbo() const;
	uint32_t& getVbo();

	void updateMatrices();

	virtual void draw() = 0;
	virtual void idleUpdate(float delta) = 0;

protected:
	VAO m_vao;
	VBO m_vbo;
	ShaderProgram shaderProgram;

	glm::mat4 m_model{1.f};
	glm::mat4 m_view{1.f};
	glm::mat4 m_projection{1.f};

	Vector2 m_globalPosition;
};

//------------------------------------------------------------------//