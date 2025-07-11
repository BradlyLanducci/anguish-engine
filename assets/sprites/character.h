#pragma once

//------------------------------------------------------------------//

#include <objects/collision_object.h>
#include <texture/sprite.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
	Character();
	~Character() = default;

	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;

private:
	Sprite m_sprite;
	CollisionObject m_collision;
};

//------------------------------------------------------------------//
