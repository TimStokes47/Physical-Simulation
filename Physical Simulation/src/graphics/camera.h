#ifndef CAMERA_H
#define CAMERA_H

#include "../maths/mat4.h"

class Camera {
public:
	Camera();
	Mat4 const& getPrespectiveProjectionMatrix() const;
	Mat4 const& getViewMatrix() const;

private:
	Mat4 _perspectiveProjectionMatrix;
	Mat4 _viewMatrix;
};

#endif