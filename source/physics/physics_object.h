#pragma once

//------------------------------------------------------------------//

#include <ogl/object.h>

//------------------------------------------------------------------//

class PhysicsObject : public Object
{
public:
	PhysicsObject() = default;
	virtual ~PhysicsObject() = default;

	void _physicsUpdate(float delta);

	void setStatic(bool isStatic);

	Rect getRect()
	{
		return Rect(m_globalPosition, m_size * m_scale);
	}

protected:
	virtual void physicsUpdate(float delta) = 0;
	Vector2 m_size;
	Vector2 m_scale{1.f, 1.f};

	bool m_isStatic{false};
};

//------------------------------------------------------------------//
