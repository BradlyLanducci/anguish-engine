#include <sprites/character.h>
#include <utilities/keyboard.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Character::Character()
{
	setTexture("assets/textures/test.png");
	m_scale = Vector2(3.f, 3.f);
}

//------------------------------------------------------------------//

void Character::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//

void Character::physicsUpdate(float delta)
{
	// Apply gravity

	m_globalPosition.y += 100 * delta;

	float amountToMove = 200.f * delta;
	if (Keyboard::isPressed(263)) // left
	{
		m_globalPosition.x -= amountToMove;
	}
	if (Keyboard::isPressed(265)) // up
	{
		m_globalPosition.y -= amountToMove;
	}
	if (Keyboard::isPressed(262)) // right
	{
		m_globalPosition.x += amountToMove;
	}
	if (Keyboard::isPressed(264)) // down
	{
		m_globalPosition.y += amountToMove;
	}
}

//------------------------------------------------------------------//
