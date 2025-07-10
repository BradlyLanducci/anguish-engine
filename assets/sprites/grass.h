#pragma once

//------------------------------------------------------------------//

#include <texture/sprite.h>

//------------------------------------------------------------------//

class Grass : public Sprite
{
public:
	Grass();
	~Grass() = default;

	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;

private:
};

//------------------------------------------------------------------//
