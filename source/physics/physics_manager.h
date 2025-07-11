#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

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
	static const std::vector<std::shared_ptr<CollisionObject>>& getCollisionObjects();
	static void addCollisionObject(std::shared_ptr<CollisionObject> collisionObject);
	static void addObject(std::shared_ptr<Object> object);
	static void update(float currentTime);

private:
	PhysicsManager() = default;
	~PhysicsManager() = default;
	PhysicsManager(const PhysicsManager&) = delete;
	PhysicsManager& operator=(const PhysicsManager&) = delete;

	static std::vector<std::shared_ptr<CollisionObject>> m_collisionObjects;
	static std::vector<std::shared_ptr<Object>> m_objects;
};

//------------------------------------------------------------------//
