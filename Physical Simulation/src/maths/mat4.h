#ifndef MAT4_H
#define MAT4_H

#include <array>

class Mat4 {
public:
	Mat4();

	std::array<float, 4> getRow(unsigned int index) const;
	std::array<float, 4> getColumn(unsigned int index) const;

private:
	static const int DIMENSIONS = 4;
	std::array<std::array<float, 4>, 4> _data;
};

#endif