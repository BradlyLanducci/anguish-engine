#pragma once

//------------------------------------------------------------------//

#include <objects/collision_object.h>
#include <objects/sprite_object.h>

//------------------------------------------------------------------//

class Character : public Object
{
public:
	Character();
	~Character() = default;

	void idleUpdate(float delta);
	void physicsUpdate(float delta);

private:
	void startJump();
	void endJump();

	bool m_applyGravity{true};
	bool m_isJumping{false};
	float m_jumpAccumulator{0.f};
	const float m_jumpSeconds{0.5f};
	uint32_t m_jumpPressed{0};

	Sprite* m_sprite;
	CollisionObject* m_collision;
};

//------------------------------------------------------------------//
