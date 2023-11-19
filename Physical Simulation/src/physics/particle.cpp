#include "particle.h"

Particle::Particle()
	: position(), velocity(), _forceAccumulator(), inverseMass(1.0f)
{
}

void Particle::applyForce(const Vec3& force)
{
	_forceAccumulator = _forceAccumulator + force;
}

void Particle::update(float dt)
{
	Vec3 acceleration = _forceAccumulator * inverseMass;
	velocity = velocity + acceleration * dt;
	position = position + velocity * dt;

	_forceAccumulator = Vec3();
}
