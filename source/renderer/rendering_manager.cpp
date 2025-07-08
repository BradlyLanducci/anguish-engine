#include <renderer/rendering_manager.h>
#include <texture/sprite.h>
#include <utilities/window.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

constexpr float PHYSICS_INTERVAL = 1.f / 60.f;

//------------------------------------------------------------------//

std::vector<std::shared_ptr<Sprite>> RenderingManager::m_sprites;

//------------------------------------------------------------------//

void RenderingManager::destroy()
{
	m_sprites.clear();
}

//------------------------------------------------------------------//

RenderingManager& RenderingManager::get()
{
	static RenderingManager p;
	return p;
}

//------------------------------------------------------------------//

void RenderingManager::addObject(std::shared_ptr<Sprite> sprite)
{
	m_sprites.push_back(sprite);
	LOG(INFO) << "Added object now we have " << m_sprites.size() << " objects";
}

//------------------------------------------------------------------//

void RenderingManager::update(float currentTime)
{
	for (const auto& sprite : m_sprites)
	{
		Vector2 windowSize{Window::getSize()};
		glm::mat4 projection = glm::ortho(0.0f, windowSize.x, windowSize.y, 0.0f);
		sprite->setProjectionMatrix(projection);
		sprite->draw();
	}
}

//------------------------------------------------------------------//
