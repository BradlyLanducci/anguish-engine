#pragma once

//------------------------------------------------------------------//

#include <utilities/data_structures.h>
#include <shaders/shader_program.h>

#include <cstdint>
#include <array>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Texture : public GlObject
{
public:
	Texture();
	~Texture() = default;

	Vector2i getSize() const;
	void setSize(Vector2i size);

	void load(const std::string& path);

protected:
	uint8_t* mp_data{nullptr};
	Vector2i m_size;
	int m_channels{0};
};

//------------------------------------------------------------------//
