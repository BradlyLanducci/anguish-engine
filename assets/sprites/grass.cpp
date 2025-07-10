#include <sprites/grass.h>

//------------------------------------------------------------------//

Grass::Grass()
{
	setTexture("assets/textures/grass.png");
	setStatic(true);
	m_globalPosition = Vector2(0, 540);
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
