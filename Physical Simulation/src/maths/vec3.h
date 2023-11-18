#ifndef VEC3_H
#define VEC3_H

#include <array>

class Vec3 {
public:
	Vec3();
	Vec3(float x, float y, float z);

	const float x() const;
	const float y() const;
	const float z() const;

	float& operator[](int index);

	friend float dot(const Vec3& lhs, const Vec3& rhs);

	friend Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
	friend Vec3 operator-(const Vec3& lhs, const Vec3& rhs);

private:
	static const int DIMENSIONS = 3;
	std::array<float, DIMENSIONS> _data;
};

#endif