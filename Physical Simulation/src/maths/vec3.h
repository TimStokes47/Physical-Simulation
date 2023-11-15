#ifndef VEC3_H
#define VEC3_H

class Vec3 {
public:
	Vec3(float x, float y, float z);

	const float x() const;
	const float y() const;
	const float z() const;

private:
	static const int DIMENSIONS = 3;
	float _data[DIMENSIONS];
};

#endif