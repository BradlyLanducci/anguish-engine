#include <sprites/grass.h>

//------------------------------------------------------------------//

Grass::Grass()
		: Object()
		, m_sprite(new Sprite())
		, m_collision(new CollisionObject())
{
	addChild(m_sprite);
	addChild(m_collision);
	m_sprite->setTexture("assets/textures/grass.png");
	m_collision->setSize(m_sprite->rect().size);
	setGlobalPosition(Vector2(0, 540));
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
