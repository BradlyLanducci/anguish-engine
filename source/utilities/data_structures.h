#pragma once

//------------------------------------------------------------------//

#include <cstdint>

//------------------------------------------------------------------//

struct Vector2
{
	Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
	{
	}

	Vector2()
	{
	}

	Vector2 operator*(float f)
	{
		this->x *= f;
		this->y *= f;
		return *this;
	}

	Vector2 operator*(const Vector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	float x{0.f};
	float y{0.f};
};

#define DEFAULT_SCALE Vector2(1.f, 1.f)

//------------------------------------------------------------------//

struct Vector2i
{
	Vector2i(int _x, int _y)
			: x(_x)
			, y(_y)
	{
	}

	Vector2i()
	{
	}

	Vector2i operator*(float f)
	{
		this->x *= f;
		this->y *= f;
		return *this;
	}

	Vector2i operator*(const Vector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	Vector2i operator*(const Vector2i& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	int x{0};
	int y{0};
};

//------------------------------------------------------------------//
