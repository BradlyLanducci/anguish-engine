#pragma once

//------------------------------------------------------------------//

#include <physics/physics_object.h>
#include <texture/texture.h>
#include <ogl/vao.h>
#include <ogl/vbo.h>
#include <ogl/ebo.h>

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

	void setTexture(const std::string& texturePath);

private:
	Texture m_texture;

	VAO m_vao;
	VBO m_vbo;
	EBO m_ebo;
	ShaderProgram m_shaderProgram;
	glm::mat4 m_model{1.f};

	// These are temporarily on an object level, ultimately projection matrix will be on a renderer level and the view
	// matrix will be on a camera level
	glm::mat4 m_view{1.f};
	Vector2 m_scale{1.f, 1.f};
};

//------------------------------------------------------------------//
