#pragma once

#include <objects/item.h>
#include <utilities/data_structures.h>
#include <idle/idle_manager.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

class Object : public Item
{
public:
	Object()
	{
		std::shared_ptr<Object> obj = std::shared_ptr<Object>(this);
		IdleManager::addObject(obj);
		PhysicsManager::addObject(obj);
	}
	virtual ~Object() = default;

	virtual void idleUpdate(float delta) = 0;
	virtual void physicsUpdate(float delta) = 0;

	Rect rect()
	{
		return Rect(m_globalPosition, m_size * m_scale);
	}

	Vector2 globalPosition() const
	{
		return m_globalPosition;
	}

	Vector2 size() const
	{
		return m_size;
	}

	Vector2 scale() const
	{
		return m_scale;
	}

	void setRect(Rect rect)
	{
		m_globalPosition = rect.origin;
		m_size = rect.size;
	}

	void setGlobalPosition(Vector2 globalPosition)
	{
		m_globalPosition = globalPosition;
	}

	void setSize(Vector2 size)
	{
		m_size = size;
	}

	void setScale(Vector2 scale)
	{
		m_scale = scale;
	}

protected:
	Vector2 m_globalPosition;
	Vector2 m_size;
	Vector2 m_scale{1.f, 1.f};
};

//------------------------------------------------------------------//
