#include "camera.h"


Camera::Camera()
	: _position(0.0f, 0.0f, 10.0f), _viewDirection(0.0f, 0.0f, -1.0f), _up(0.0f, 1.0f, 0.0f)
{
	_perspectiveProjectionMatrix = Mat4::perspectiveProjection(96.0f / 54.0f, 0.6f, 0.1f, 100.0f);
	_viewMatrix = Mat4::lookAt(_position, _position + _viewDirection, _up);
}

Mat4 const& Camera::getPrespectiveProjectionMatrix() const
{
	return _perspectiveProjectionMatrix;
}

Mat4 const& Camera::getViewMatrix() const
{
	return _viewMatrix;
}
