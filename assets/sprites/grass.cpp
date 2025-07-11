#include <sprites/grass.h>

//------------------------------------------------------------------//

Grass::Grass()
{
	m_sprite.setTexture("assets/textures/grass.png");
	m_collision.setSize(m_sprite.rect().size);
	setGlobalPosition(Vector2(0, 540));
	m_sprite.setGlobalPosition(m_globalPosition);
	m_collision.setGlobalPosition(m_globalPosition);
}

//------------------------------------------------------------------//

void Grass::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Grass::physicsUpdate(float delta)
{
}

//------------------------------------------------------------------//
