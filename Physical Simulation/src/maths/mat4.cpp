#include "mat4.h"
#include "mat4.h"

#include "vec3.h"
#include <cmath>

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

std::array<float, 4>& Mat4::operator[](int index) {
	return _data[index];
}

std::array<float, 4> const& Mat4::operator[](int index) const {
	return _data[index];
}

Mat4 Mat4::perspectiveProjection(float aspectRatio, float fieldOfView, float nearPlane, float farPlane) {
	Mat4 projectionMatrix;
	float tan = std::tanf(fieldOfView / 2.0f);

	projectionMatrix[0][0] = 1.0f / (aspectRatio * tan);
	projectionMatrix[1][1] = 1.0f / tan;
	projectionMatrix[2][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);
	projectionMatrix[3][3] = 0.0f;
	projectionMatrix[2][3] = -1.0f;
	projectionMatrix[3][2] = -2.0f * farPlane * nearPlane / (farPlane - nearPlane);

	return projectionMatrix;
}

Mat4 Mat4::lookAt(const Vec3& origin, const Vec3& target, const Vec3& up)
{
	Vec3 localZ = normalise(target - origin);
	Vec3 localX = normalise(cross(localZ, up));
	Vec3 localY = cross(localX, localZ);

	Mat4 lookAtMatrix;
	lookAtMatrix[0][0] = localX.x;
	lookAtMatrix[0][1] = localY.x;
	lookAtMatrix[0][2] = localZ.x;

	lookAtMatrix[1][0] = localX.y;
	lookAtMatrix[1][1] = localY.y;
	lookAtMatrix[1][2] = localZ.y;

	lookAtMatrix[2][0] = localX.z;
	lookAtMatrix[2][1] = localY.z;
	lookAtMatrix[2][2] = localZ.z;

	lookAtMatrix[3][0] = -dot(origin, localX);
	lookAtMatrix[3][1] = -dot(origin, localY);
	lookAtMatrix[3][2] = dot(origin, localZ);

	return lookAtMatrix;
}

Mat4 Mat4::translation(const Vec3& vector) {
	Mat4 translationMatrix;
	translationMatrix[3][0] = vector.x;
	translationMatrix[3][1] = vector.y;
	translationMatrix[3][2] = vector.z;
	return translationMatrix;
}

const int Mat4::DIMENSIONS;