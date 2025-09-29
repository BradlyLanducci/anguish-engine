#include <utilities/camera.h>
#include <renderer/rendering_manager.h>
#include <utilities/window.h>

//------------------------------------------------------------------//

Camera &Camera::get()
{
    static Camera c;
    return c;
}

//------------------------------------------------------------------//

Camera::Camera()
    : Object(false, false)
{
    moved.connect([this]()
    {
        Vector2 gp{ globalPosition() };
        glm::mat4 translate = glm::translate(m_view, { -gp.x + static_cast<float>(WINDOW_WIDTH) / 2.f,
                                                       -gp.y + static_cast<float>(WINDOW_HEIGHT) / 2.f, 0.0f });
        RenderingManager::setViewMatrix(translate);
    });
}

//------------------------------------------------------------------//
