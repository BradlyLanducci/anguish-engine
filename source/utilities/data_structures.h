#pragma once

//------------------------------------------------------------------//

#include <cstdint>

//------------------------------------------------------------------//

struct Vector2i;

struct Vector2
{
	Vector2(float _x, float _y);
	Vector2() = default;

	Vector2 operator*(float f);
	Vector2 operator*(const Vector2& other);
	Vector2 operator*(const Vector2i& other);

	float x{0.f};
	float y{0.f};
};

//------------------------------------------------------------------//

struct Vector2i
{
	Vector2i(int _x, int _y);
	Vector2i() = default;

	Vector2i operator*(uint32_t i);
	Vector2i operator*(float f);
	Vector2i operator*(const Vector2& other);
	Vector2i operator*(const Vector2i& other);

	int x{0};
	int y{0};
};

//------------------------------------------------------------------//
