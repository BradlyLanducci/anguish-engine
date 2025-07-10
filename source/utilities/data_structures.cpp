#include "data_structures.h"

//------------------------------------------------------------------//

Vector2::Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
{
}

//------------------------------------------------------------------//

Vector2::Vector2(Vector2i vi)
		: x((float)vi.x)
		, y((float)vi.y)
{
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(float f)
{
	Vector2 result;
	result.x = this->x * f;
	result.y = this->y * f;
	return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2& other)
{
	Vector2 result;
	result.x = this->x * other.x;
	result.y = this->y * other.y;
	return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator*(const Vector2i& other)
{
	Vector2 result;
	result.x = this->x * other.x;
	result.y = this->y * other.y;
	return result;
}

//------------------------------------------------------------------//

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;
	return result;
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

Vector2 Rect::topLeft() const
{
	return this->origin;
}

//------------------------------------------------------------------//

Vector2 Rect::topRight() const
{
	return Vector2(this->origin.x + this->size.x, this->origin.y);
}

//------------------------------------------------------------------//

Vector2 Rect::bottomLeft() const
{
	return Vector2(this->origin.x, this->origin.y + this->size.y);
}

//------------------------------------------------------------------//

Vector2 Rect::bottomRight()
{
	return Vector2(this->origin + this->size);
}

//------------------------------------------------------------------//

Rect Rect::scale(Vector2 v)
{
	Rect result(this->origin, Vector2());
	result.size.x = this->size.x * v.x;
	result.size.y = this->size.y * v.y;
	return result;
}

//------------------------------------------------------------------//
