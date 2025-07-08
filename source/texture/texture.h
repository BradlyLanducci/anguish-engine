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

constexpr uint32_t NUM_VERTICES = 18; // Rectangle

//------------------------------------------------------------------//

class Texture
{
public:
	Texture();
	~Texture();

	Vector2 get_size() const;
	void setSize(Vector2 size);

	const std::array<float, NUM_VERTICES>& getVertices();

	void setProjectionMatrix(glm::mat4 projection);

	void draw();

	uint32_t getVao() const;
	uint32_t getVbo() const;
	uint32_t& getVbo();

protected:
	void updateMatrices();

	std::array<float, NUM_VERTICES> m_vertices;
	Vector2 m_size;

	VAO m_vao;
	VBO m_vbo;
	ShaderProgram m_shaderProgram;

	glm::mat4 m_model{1.f};

	// These are temporarily on an object level, ultimately projection matrix will be on a renderer level and the view
	// matrix will be on a camera level
	glm::mat4 m_view{1.f};
};

//------------------------------------------------------------------//
