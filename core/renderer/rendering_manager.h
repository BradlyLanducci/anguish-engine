#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Sprite;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class RenderingManager
{
public:
	static void destroy();
	static RenderingManager& get();
	static void addObject(Sprite* object);
	static void update(float currentTime);

	RenderingManager(const RenderingManager&) = delete;
	RenderingManager& operator=(const RenderingManager&) = delete;

private:
	RenderingManager() = default;
	~RenderingManager() = default;

	static std::vector<Sprite*> m_sprites;
};

//------------------------------------------------------------------//
