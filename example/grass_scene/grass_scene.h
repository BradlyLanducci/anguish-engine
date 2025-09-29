#pragma once

#include <grass_scene/sprites/grass.h>
#include <grass_scene/sprites/character.h>
#include <scenes/scene.h>

//------------------------------------------------------------------//

class GrassScene : public Scene
{
public:
    GrassScene();
    ~GrassScene() override = default;

private:
    Character *c{ nullptr };
    Grass *g{ nullptr };
};

//------------------------------------------------------------------//
