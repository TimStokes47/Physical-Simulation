#include "uvec3.h"
#include "uvec3.h"

// Constructors

UVec3::UVec3()
	: _data{ 0, 0, 0 }
{
}

UVec3::UVec3(unsigned int x, unsigned int y, unsigned int z)
	: _data{ x, y, z }
{
}

// Data access

const unsigned int UVec3::x() const
{
	return _data[0];
}

const unsigned int UVec3::y() const
{
	return _data[1];
}

const unsigned int UVec3::z() const
{
	return _data[2];
}

unsigned int& UVec3::operator[](int index) {
	return _data[index];
}

unsigned int const& UVec3::operator[](int index) const
{
	return _data[index];
}

const int UVec3::DIMENSIONS;