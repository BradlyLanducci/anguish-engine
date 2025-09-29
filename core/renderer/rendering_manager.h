#pragma once

//------------------------------------------------------------------//

#include <vector>
#include <glm/gtc/matrix_transform.hpp>

//------------------------------------------------------------------//

class Sprite;

//------------------------------------------------------------------//

/// @brief Manages all physics objects in the engine
class RenderingManager
{
public:
    static RenderingManager &get();
    static void addObject(Sprite *object);
    static void update(float currentTime);

    static void setViewMatrix(const glm::mat4 &view);

    RenderingManager(const RenderingManager &) = delete;
    RenderingManager &operator=(const RenderingManager &) = delete;

private:
    RenderingManager() = default;
    ~RenderingManager() = default;

    static std::vector<Sprite *> m_sprites;
    static glm::mat4 m_projection;
    static glm::mat4 m_view;
};

//------------------------------------------------------------------//
