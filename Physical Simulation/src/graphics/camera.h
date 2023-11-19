#ifndef CAMERA_H
#define CAMERA_H

#include "../maths/mat4.h"
#include "../maths/vec3.h"

class Camera {
public:
	Camera();
	Mat4 const& getPrespectiveProjectionMatrix() const;
	Mat4 const& getViewMatrix() const;

private:
	Mat4 _perspectiveProjectionMatrix;
	Mat4 _viewMatrix;

	Vec3 _position;
	Vec3 _viewDirection;
	Vec3 _up;
};

#endif