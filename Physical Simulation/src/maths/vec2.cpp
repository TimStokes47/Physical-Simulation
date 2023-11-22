#include "vec2.h"
#include <cmath>

// Constructors

Vec2::Vec2()
	: x(0.0f), y(0.0f)
{
}

Vec2::Vec2(float x, float y) 
	: x(x), y(y)
{
}

// Vector Specific Functions

float magnitudeSquared(const Vec2& vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

Vec2 normalise(const Vec2& vector)
{
	float squareMagnitude = magnitudeSquared(vector);
	if (squareMagnitude != 0.0f) {
		return vector / std::sqrtf(squareMagnitude);
	}
	else {
		return vector;
	}
}

float dot(const Vec2& lhs, const Vec2& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

// Operator Overloads

Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
	Vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return result;
}

Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
	Vec2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	return result;
}

Vec2 operator/(const Vec2& lhs, float rhs)
{
	Vec2 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;
	return result;
}

Vec2 operator*(const Vec2& lhs, float rhs)
{
	Vec2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	return result;
}
