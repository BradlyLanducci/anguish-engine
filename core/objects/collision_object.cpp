#include <objects/collision_object.h>
#include <physics/physics_manager.h>

//------------------------------------------------------------------//

CollisionObject::CollisionObject()
{
	addPhysicsCb([this] (float delta) { physicsUpdate(delta); });
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
