#include <objects/collision_object.h>
#include <physics/physics_manager.h>
#include "collision_object.h"

CollisionObject::CollisionObject()
{
	PhysicsManager::addCollisionObject(std::shared_ptr<CollisionObject>(this));
}

void CollisionObject::physicsUpdate(float delta)
{
}

void CollisionObject::idleUpdate(float delta)
{
}
