#ifndef PARTICLE_H
#define PARTICLE_H

#include "../maths/vec3.h"

class Particle {
public:
	Particle();
	Vec3 position;
	Vec3 velocity;
	
private:
	Vec3 _forceAccumulator;
};

#endif