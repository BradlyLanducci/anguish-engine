#include <texture/texture.h>

#include <glad/glad.h>

//------------------------------------------------------------------//

Vector2 Texture::getSize() const
{
	return m_size;
}

//------------------------------------------------------------------//

void Texture::setSize(Vector2 size)
{
	m_size = size;
}

//------------------------------------------------------------------//