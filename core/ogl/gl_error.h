#pragma once

//------------------------------------------------------------------//

#include <glad/glad.h>
#include <glog/logging.h>

//------------------------------------------------------------------//

static void checkGLError()
{
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		LOG(ERROR) << err << " ";
	}
}

//------------------------------------------------------------------//
