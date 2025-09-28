#pragma once

//------------------------------------------------------------------//

#include <objects/collision_object.h>
#include <objects/sprite_object.h>

//------------------------------------------------------------------//

class Grass : public Object
{
public:
	Grass();
	~Grass() = default;

	void idleUpdate(float delta);
	void physicsUpdate(float delta);

private:
	Sprite* m_sprite;
	CollisionObject* m_collision;
};

//------------------------------------------------------------------//
