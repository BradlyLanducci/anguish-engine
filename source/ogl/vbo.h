#pragma once

//------------------------------------------------------------------//

#include "gl_object.h"

#include <cstdint>

//------------------------------------------------------------------//

// Vertex Buffer Object
// Really just a raw data buffer

class VBO : public GlObject
{
public:
	VBO();
	~VBO() override;

	uint32_t& get();
	uint32_t get() const;
};

//------------------------------------------------------------------//
