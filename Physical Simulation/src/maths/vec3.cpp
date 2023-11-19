#include "vec3.h"
#include <cmath>

// Constructors

Vec3::Vec3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vec3::Vec3(float x, float y, float z) 
	: x(x), y(y), z(z)
{
}

// Vector Specific Functions

float magnitudeSquared(const Vec3& vector)
{
	return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

float dot(const Vec3& lhs, const Vec3& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vec3 cross(const Vec3& lhs, const Vec3& rhs) {
	return Vec3(lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x
	);
}

// Operator Overloads

Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
	Vec3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	return result;
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
	Vec3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;
	return result;
}

Vec3 operator/(const Vec3& lhs, float rhs)
{
	Vec3 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;
	result.z = lhs.z / rhs;
	return result;
}
