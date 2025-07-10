#include <physics/physics_object.h>
#include <physics/physics_manager.h>
#include <physics/aabb.h>
#include "physics_object.h"

//------------------------------------------------------------------//

void PhysicsObject::_physicsUpdate(float delta)
{
	physicsUpdate(delta);

	if (!m_isStatic)
	{
		auto objects = PhysicsManager::getPhysicsObjects();
		m_globalPosition.x = std::round(m_globalPosition.x);
		m_globalPosition.y = std::round(m_globalPosition.y);

		for (const auto& obj : objects)
		{
			if (obj.get() != this)
			{
				Rect r1 = getRect();
				Rect r2 = obj->getRect();
				if (AABB::aabb(r1, r2))
				{
					Vector2 offset = AABB::collide(r1, r2);
					m_globalPosition = m_globalPosition + offset;
					m_globalPosition.x = std::round(m_globalPosition.x);
					m_globalPosition.y = std::round(m_globalPosition.y);
				}
			}
		}
	}
}

//------------------------------------------------------------------//

void PhysicsObject::setStatic(bool isStatic)
{
	m_isStatic = isStatic;
}

//------------------------------------------------------------------//
