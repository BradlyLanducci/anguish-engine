#pragma once

//------------------------------------------------------------------//

#include "gl_object.h"

#include <cstdint>

//------------------------------------------------------------------//

// Vertex Array Object
class VAO : public GlObject
{
public:
	VAO();
	~VAO() override = default;
};

//------------------------------------------------------------------//
