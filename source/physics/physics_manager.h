#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class PhysicsObject;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class PhysicsManager
{
public:
	static void destroy();
	static PhysicsManager& get();
	static const std::vector<std::shared_ptr<PhysicsObject>>& PhysicsManager::getPhysicsObjects();
	static void addObject(std::shared_ptr<PhysicsObject> object);
	static void update(float currentTime);

private:
	PhysicsManager() = default;
	~PhysicsManager() = default;
	PhysicsManager(const PhysicsManager&) = delete;
	PhysicsManager& operator=(const PhysicsManager&) = delete;

	static std::vector<std::shared_ptr<PhysicsObject>> m_objects;
};

//------------------------------------------------------------------//
