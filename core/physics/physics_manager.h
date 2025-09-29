#pragma once

//------------------------------------------------------------------//

#include <vector>

//------------------------------------------------------------------//

class Object;
class CollisionObject;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class PhysicsManager
{
public:
	static void destroy();
	static PhysicsManager& get();
	static const std::vector<CollisionObject*>& getCollisionObjects();
	static void addCollisionObject(CollisionObject* collisionObject);
	static void addObject(Object* object);
	static void update(float currentTime);

	PhysicsManager(const PhysicsManager&) = delete;
	PhysicsManager& operator=(const PhysicsManager&) = delete;

private:
	PhysicsManager() = default;
	~PhysicsManager() = default;

	static std::vector<CollisionObject*> m_collisionObjects;
	static std::vector<Object*> m_objects;
};

//------------------------------------------------------------------//
