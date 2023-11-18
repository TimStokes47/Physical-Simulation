#include "vec3.h"
#include "vec3.h"

// Constructors

Vec3::Vec3()
	: _data{ 0.0f, 0.0f, 0.0f }
{
}

Vec3::Vec3(float x, float y, float z) 
	: _data{ x, y, z }
{
}

// Data access

const float Vec3::x() const
{
	return _data[0];
}

const float Vec3::y() const
{
	return _data[1];
}

const float Vec3::z() const
{
	return _data[2];
}

float& Vec3::operator[](int index) {
	return _data[index];
}

float dot(const Vec3& lhs, const Vec3& rhs) {
	return lhs._data[0] * rhs._data[0] + lhs._data[1] * rhs._data[1] + lhs._data[2] * rhs._data[2];
}

Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
	Vec3 result;
	result._data[0] = lhs._data[0] + rhs._data[0];
	result._data[1] = lhs._data[1] + rhs._data[1];
	result._data[2] = lhs._data[2] + rhs._data[2];
	return result;
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
	Vec3 result;
	result._data[0] = lhs._data[0] - rhs._data[0];
	result._data[1] = lhs._data[1] - rhs._data[1];
	result._data[2] = lhs._data[2] - rhs._data[2];
	return result;
}

const int Vec3::DIMENSIONS;