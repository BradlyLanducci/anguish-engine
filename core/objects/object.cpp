#include <objects/object.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

Object::Object()
{
	IdleManager::addObject(this);
	PhysicsManager::addObject(this);
}

//------------------------------------------------------------------//

Object::~Object()
{
	for (auto& c : m_children)
	{
		if (c)
		{
			delete c;
			c = nullptr;
		}
	}

	m_children.clear();
}

//------------------------------------------------------------------//

void Object::addChild(Object* child)
{
	child->setParent(this);
	m_children.push_back(child);
}

//------------------------------------------------------------------//

void Object::addIdleCb(std::function<void(float)> cb)
{
	m_idleCbs.push_back(cb);
}

//------------------------------------------------------------------//

void Object::addPhysicsCb(std::function<void(float)> cb)
{
	m_physicsCbs.push_back(cb);
}
//------------------------------------------------------------------//

void Object::setParent(Object* parent)
{
	m_parent = parent;
}

//------------------------------------------------------------------//

Object* Object::getParent() const
{
	return m_parent;
}

//------------------------------------------------------------------//

void Object::idleUpdate(float delta)
{
	for (const auto& cb : m_idleCbs)
	{
		cb(delta);
	}
}

//------------------------------------------------------------------//

void Object::physicsUpdate(float delta)
{
	for (const auto& cb : m_physicsCbs)
	{
		cb(delta);
	}
}

//------------------------------------------------------------------//

Rect Object::rect() const
{
	return m_rect;
}

//------------------------------------------------------------------//

Vector2 Object::globalPosition() const
{
	return m_rect.origin;
}

//------------------------------------------------------------------//

Vector2 Object::size() const
{
	return m_rect.size;
}

//------------------------------------------------------------------//

Vector2 Object::scale() const
{
	return m_rect.scale;
}

//------------------------------------------------------------------//

void Object::setRect(Rect rect)
{
	m_rect = rect;
}

//------------------------------------------------------------------//

void Object::setGlobalPosition(Vector2 globalPosition)
{
	globalPosition.roundToInt();
	m_rect.origin = globalPosition;
	for (auto& c : m_children)
	{
		c->setGlobalPosition(globalPosition);
	}
}

//------------------------------------------------------------------//

void Object::setSize(Vector2 size)
{
	m_rect.size = size;
}

//------------------------------------------------------------------//

void Object::setScale(Vector2 scale)
{
	m_rect.scale = scale;
}

//------------------------------------------------------------------//
