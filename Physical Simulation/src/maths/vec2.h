#ifndef VEC3_H
#define VEC3_H

#include <array>

class Vec2 {
public:
	Vec2();
	Vec2(float x, float y);

	float x;
	float y;
};

float magnitudeSquared(const Vec2& vector);
Vec2 normalise(const Vec2& vector);

float dot(const Vec2& lhs, const Vec2& rhs);

Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
Vec2 operator-(const Vec2& lhs, const Vec2& rhs);
Vec2 operator/(const Vec2& lhs, float rhs);
Vec2 operator*(const Vec2& lhs, float rhs);

#endif