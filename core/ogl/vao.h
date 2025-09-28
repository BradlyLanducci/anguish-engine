#pragma once

//------------------------------------------------------------------//

#include <ogl/gl_object.h>

#include <cstdint>

//------------------------------------------------------------------//

// Vertex Array Object
class VAO final : public GlObject
{
public:
	VAO();
	~VAO() override;
};

//------------------------------------------------------------------//
