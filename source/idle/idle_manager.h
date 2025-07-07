#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Object;

//------------------------------------------------------------------//

/// @brief Manages all objects idle time in the engine
class IdleManager
{
public:
	static void destroy();
	static IdleManager& get();
	static void addObject(std::shared_ptr<Object> object);
	static void update(float currentTime);

private:
	IdleManager() = default;
	~IdleManager() = default;
	IdleManager(const IdleManager&) = delete;
	IdleManager& operator=(const IdleManager&) = delete;

	static std::vector<std::shared_ptr<Object>> m_objects;
};

//------------------------------------------------------------------//
