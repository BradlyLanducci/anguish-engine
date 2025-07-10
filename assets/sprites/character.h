#pragma once

//------------------------------------------------------------------//

#include <texture/sprite.h>

//------------------------------------------------------------------//

class Character : public Sprite
{
public:
	Character();
	~Character() = default;

	void idleUpdate(float delta) override;
	void physicsUpdate(float delta) override;

private:
};

//------------------------------------------------------------------//
