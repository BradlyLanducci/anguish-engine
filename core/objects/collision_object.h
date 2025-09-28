#pragma once

#include <objects/object.h>
#include <utilities/signal.h>

//------------------------------------------------------------------//

class CollisionObject : public Object
{
public:
	CollisionObject();
	~CollisionObject() override = default;

	Signal collided;

private:
	void physicsUpdate(float delta) override;
	void idleUpdate(float delta) override;
};

//------------------------------------------------------------------//