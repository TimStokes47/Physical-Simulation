#ifndef VEC3_H
#define VEC3_H

#include <array>

class Vec3 {
public:
	Vec3();
	Vec3(float x, float y, float z);

	float x;
	float y;
	float z;
};

float magnitudeSquared(const Vec3& vector);

float dot(const Vec3& lhs, const Vec3& rhs);
Vec3 cross(const Vec3& lhs, const Vec3& rhs);

Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
Vec3 operator/(const Vec3& lhs, float rhs);

#endif