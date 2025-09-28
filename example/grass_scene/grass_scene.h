#pragma once

#include <objects/object.h>

#include <sprites/character.h>
#include <sprites/grass.h>

//------------------------------------------------------------------//

class Scene : public Object
{
public:
	Scene();
	~Scene() = default;

private:
	Character* c{nullptr};
	Grass* g{nullptr};
};

//------------------------------------------------------------------//
// #include <scenes/scene.h>

// //------------------------------------------------------------------//

// Scene::Scene()
// 		: c(new Character)
// 		, g(new Grass)
// {
// 	addChild(c);
// 	addChild(g);
// }

// //------------------------------------------------------------------//
