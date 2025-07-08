#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <memory>

//------------------------------------------------------------------//

class Texture;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class RenderingManager
{
public:
	static void destroy();
	static RenderingManager& get();
	static void addObject(std::shared_ptr<Texture> object);
	static void update(float currentTime);

private:
	RenderingManager() = default;
	~RenderingManager() = default;
	RenderingManager(const RenderingManager&) = delete;
	RenderingManager& operator=(const RenderingManager&) = delete;

	static std::vector<std::shared_ptr<Texture>> m_textures;
};

//------------------------------------------------------------------//
