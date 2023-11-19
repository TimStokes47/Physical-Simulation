#include "camera.h"
#include "../core/input.h"


Camera::Camera()
	: _position(0.0f, 0.0f, 10.0f), _viewDirection(0.0f, 0.0f, -1.0f), _up(0.0f, 1.0f, 0.0f), _speed(3.0f)
{
	_perspectiveProjectionMatrix = Mat4::perspectiveProjection(96.0f / 54.0f, 0.6f, 0.1f, 100.0f);
	_viewMatrix = Mat4::lookAt(_position, _position + _viewDirection, _up);
}

void Camera::update(float dt) {
	Vec3 localX = cross(_up, _viewDirection);
	Vec3 velocity;

	if (Input::isKeyPressed(GLFW_KEY_A)) {
		velocity = velocity + localX;
	}
	if (Input::isKeyPressed(GLFW_KEY_D)) {
		velocity = velocity - localX;
	}
	if (Input::isKeyPressed(GLFW_KEY_W)) {
		velocity = velocity + _viewDirection;
	}
	if (Input::isKeyPressed(GLFW_KEY_S)) {
		velocity = velocity - _viewDirection;
	}

	_position = _position + normalise(velocity) * _speed * dt;
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
