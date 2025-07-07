#pragma once

#include <ogl/object.h>

class PhysicsObject : public Object
{
public:
	PhysicsObject() = default;
	virtual ~PhysicsObject() = default;

	virtual void physicsUpdate(float delta) = 0;
};