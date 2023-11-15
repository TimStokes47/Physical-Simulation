#include "vec3.h"
#include "vec3.h"

// Constructors

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

const int Vec3::DIMENSIONS;