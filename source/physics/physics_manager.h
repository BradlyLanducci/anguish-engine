#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

constexpr float PHYSICS_UPDATE_INTERVAL = 0.5f;

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class PhysicsManager
{
public:
	static void destroy();
	static PhysicsManager& get();
	static void addObject(std::shared_ptr<Object> object);
	static void update(float currentTime);

private:
	PhysicsManager() = default;
	~PhysicsManager() = default;
	PhysicsManager(const PhysicsManager&) = delete;
	PhysicsManager& operator=(const PhysicsManager&) = delete;

	static std::vector<std::shared_ptr<Object>> m_objects;
};

//------------------------------------------------------------------//
