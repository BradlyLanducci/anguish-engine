#pragma once

#include <objects/object.h>

#include <grass_scene/sprites/grass.h>
#include <grass_scene/sprites/character.h>
#include <scenes/scene.h>

//------------------------------------------------------------------//

class GrassScene : public Scene
{
public:
	GrassScene();
	~GrassScene() = default;

private:
	Character* c{nullptr};
	Grass* g{nullptr};
};

//------------------------------------------------------------------//
