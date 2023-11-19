#ifndef PARTICLE_H
#define PARTICLE_H

#include "../maths/vec3.h"

class Particle {
public:
	Particle();
	Vec3 position;
	Vec3 velocity;
	float inverseMass;

	void applyForce(const Vec3& force);
	void update(float dt);
	
private:
	Vec3 _forceAccumulator;
};

#endif