#include <texture/sprite.h>
#include <renderer/rendering_manager.h>
#include <idle/idle_manager.h>
#include <utilities/keyboard.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

Sprite::Sprite()
{
	std::shared_ptr<Sprite> sprite = std::shared_ptr<Sprite>(this);
	RenderingManager::addObject(sprite);
	IdleManager::addObject(sprite);
	PhysicsManager::addObject(sprite);
}

//------------------------------------------------------------------//

void Sprite::idleUpdate(float delta)
{
	m_model = glm::translate(glm::mat4(1.0f), glm::vec3(m_globalPosition.x, m_globalPosition.y, 0.f));
}

//------------------------------------------------------------------//

void Sprite::physicsUpdate(float delta)
{
	float amountToMove = 60.f * delta;
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
