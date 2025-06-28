#pragma once

//------------------------------------------------------------------//

#include <cstdint>

//------------------------------------------------------------------//

// Base OpenGL Object
class GlObject
{
public:
	GlObject() = default;
	virtual ~GlObject() = default;

	uint32_t get() const
	{
		return m_id;
	}

	uint32_t m_id{0};
};

//------------------------------------------------------------------//