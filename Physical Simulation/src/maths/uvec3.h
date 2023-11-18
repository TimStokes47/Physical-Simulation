#ifndef UVEC3_H
#define UVEC3_H

#include <array>

class UVec3 {
public:
	UVec3();
	UVec3(unsigned int x, unsigned int y, unsigned int z);

	const unsigned int x() const;
	const unsigned int y() const;
	const unsigned int z() const;

	unsigned int& operator[](int index);
	unsigned int const& operator[](int index) const;

private:
	static const int DIMENSIONS = 3;
	std::array<unsigned int, DIMENSIONS> _data;
};

#endif