#include "data_structures.h"

//------------------------------------------------------------------//

Vector2::Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
{
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(float f)
{
	this->x *= f;
	this->y *= f;
	return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2i& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

//------------------------------------------------------------------//

Vector2i::Vector2i(int _x, int _y)
		: x(_x)
		, y(_y)
{
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(uint32_t i)
{
	this->x *= i;
	this->y *= i;
	return *this;
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(float f)
{
	this->x *= f;
	this->y *= f;
	return *this;
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(const Vector2& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

//------------------------------------------------------------------//

Vector2i Vector2i::operator*(const Vector2i& other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

//------------------------------------------------------------------//
