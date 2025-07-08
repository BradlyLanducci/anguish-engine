#pragma once

//------------------------------------------------------------------//

#include <physics/physics_object.h>
#include <texture/texture.h>

//------------------------------------------------------------------//

class Sprite : public PhysicsObject, public Texture
{
public:
	Sprite();
	~Sprite() = default;

	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;
};

//------------------------------------------------------------------//
