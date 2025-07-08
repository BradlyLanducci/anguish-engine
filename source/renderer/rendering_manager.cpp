#include <renderer/rendering_manager.h>
#include <texture/texture.h>
#include <utilities/window.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<std::shared_ptr<Texture>> RenderingManager::m_textures;

//------------------------------------------------------------------//

void RenderingManager::destroy()
{
	m_textures.clear();
}

//------------------------------------------------------------------//

RenderingManager& RenderingManager::get()
{
	static RenderingManager p;
	return p;
}

//------------------------------------------------------------------//

void RenderingManager::addObject(std::shared_ptr<Texture> texture)
{
	m_textures.push_back(texture);
	LOG(INFO) << "Added object now we have " << m_textures.size() << " objects";
}

//------------------------------------------------------------------//

void RenderingManager::update(float currentTime)
{
	for (const auto& tex : m_textures)
	{
		Vector2 windowSize{Window::getSize()};
		glm::mat4 projection = glm::ortho(0.0f, windowSize.x, windowSize.y, 0.0f);
		tex->setProjectionMatrix(projection);
		tex->draw();
	}
}

//------------------------------------------------------------------//
