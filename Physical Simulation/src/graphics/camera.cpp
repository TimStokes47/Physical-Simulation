#include "camera.h"
#include "camera.h"
#include "camera.h"

Camera::Camera() {
	_perspectiveProjectionMatrix = Mat4::perspectiveProjection(96.0f / 54.0f, 0.6f, 0.1f, 100.0f);
}

Mat4 const& Camera::getPrespectiveProjectionMatrix() const
{
	return _perspectiveProjectionMatrix;
}

Mat4 const& Camera::getViewMatrix() const
{
	return _viewMatrix;
}
