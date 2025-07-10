#pragma once

//------------------------------------------------------------------//

#include <utilities/data_structures.h>

//------------------------------------------------------------------//

class AABB
{
public:
	static bool aabb(Rect r1, Rect r2);
	static Vector2 collide(Rect r1, Rect r2);

private:
	AABB() = default;
	~AABB() = default;
};

//------------------------------------------------------------------//
