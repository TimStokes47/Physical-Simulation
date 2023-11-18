#include "mat4.h"

Mat4::Mat4()
	: _data{{ {1.0f, 0.0f, 0.0f, 0.0f},
			  {0.0f, 1.0f, 0.0f, 0.0f},
			  {0.0f, 0.0f, 1.0f, 0.0f},
			  {0.0f, 0.0f, 0.0f, 1.0f} }}
{
}

std::array<float, 4> Mat4::getRow(unsigned int index) const
{
	return _data[index];
}

std::array<float, 4> Mat4::getColumn(unsigned int index) const
{
	return { _data[0][index], _data[1][index], _data[2][index], _data[3][index] };
}

const int Mat4::DIMENSIONS;