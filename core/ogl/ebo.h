#pragma once

//------------------------------------------------------------------//

#include <ogl/gl_object.h>

#include <cstdint>

//------------------------------------------------------------------//

// Vertex Array Object
class EBO final : public GlObject
{
public:
	EBO();
	~EBO() override;
};

//------------------------------------------------------------------//
