#ifndef MAT4_H
#define MAT4_H

#include <array>

class Vec3;

class Mat4 {
public:
	Mat4();

	std::array<float, 4> getRow(unsigned int index) const;
	std::array<float, 4> getColumn(unsigned int index) const;

	std::array<float, 4>& operator[](int index);
	std::array<float, 4> const& operator[](int index) const;

	static Mat4 perspectiveProjection(float aspectRatio, float fieldOfView, float nearPlane, float farPlane);
	static Mat4 lookAt(const Vec3& origin, const Vec3& target, const Vec3& up);
	static Mat4 translation(const Vec3& vector);

private:
	static const int DIMENSIONS = 4;
	std::array<std::array<float, 4>, 4> _data;
};

#endif