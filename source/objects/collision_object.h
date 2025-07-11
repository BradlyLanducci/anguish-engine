#pragma once

#include <objects/object.h>
#include <utilities/data_structures.h>

//------------------------------------------------------------------//

class CollisionObject : public Object
{
public:
	CollisionObject();
	~CollisionObject() = default;

protected:
	void physicsUpdate(float delta) override;
	void idleUpdate(float delta) override;
	static bool m_isStatic;
};

//------------------------------------------------------------------//