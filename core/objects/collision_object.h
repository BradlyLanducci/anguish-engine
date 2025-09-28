#pragma once

#include <objects/object.h>
#include <utilities/data_structures.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

class CollisionObject : public Object
{
public:
	CollisionObject();
	~CollisionObject() = default;

	Signal collided;

private:
	void physicsUpdate(float delta);
	void idleUpdate(float delta);
};

//------------------------------------------------------------------//