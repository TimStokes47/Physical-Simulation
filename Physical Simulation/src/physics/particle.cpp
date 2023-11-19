#include "particle.h"

Particle::Particle()
	: position(), velocity(), _forceAccumulator(), inverseMass(1.0f), id(_nextID)
{
	_nextID++;
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

int Particle::_nextID = 0;