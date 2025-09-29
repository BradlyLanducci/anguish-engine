#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <utilities/data_structures.h>
#include <objects/object.h>

//------------------------------------------------------------------//

class Camera : public Object
{
public:
    static Camera &get();

private:
    Camera();
    ~Camera() override = default;

    glm::mat4 m_view{ 1.f };
};

//------------------------------------------------------------------//
