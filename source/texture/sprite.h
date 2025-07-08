#pragma once

//------------------------------------------------------------------//

#include <physics/physics_object.h>
#include <texture/texture.h>

//------------------------------------------------------------------//

constexpr uint32_t NUM_VERTICES = 12; // Rectangle

//------------------------------------------------------------------//

class Sprite : public PhysicsObject
{
public:
	Sprite();
	~Sprite() = default;

	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;

	void setProjectionMatrix(glm::mat4 projection);

	void draw();

	uint32_t getVao() const;
	uint32_t getVbo() const;
	uint32_t& getVbo();

	void setTexture(const std::string& texturePath);

private:
	void updateMatrices();
	void updateVertices();

	Texture* m_texture{nullptr};

	std::array<float, NUM_VERTICES> m_vertices;

	VAO m_vao;
	VBO m_vbo;
	ShaderProgram m_shaderProgram;

	glm::mat4 m_model{1.f};

	// These are temporarily on an object level, ultimately projection matrix will be on a renderer level and the view
	// matrix will be on a camera level
	glm::mat4 m_view{1.f};
};

//------------------------------------------------------------------//
