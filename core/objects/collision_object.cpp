#include <objects/collision_object.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

CollisionObject::CollisionObject()
		: Object()
{
	addPhysicsCb(std::bind(&CollisionObject::physicsUpdate, this, std::placeholders::_1));
	PhysicsManager::addCollisionObject(this);
}

//------------------------------------------------------------------//

void CollisionObject::physicsUpdate(float delta)
{
}

//------------------------------------------------------------------//

void CollisionObject::idleUpdate(float delta)
{
}

//------------------------------------------------------------------//
