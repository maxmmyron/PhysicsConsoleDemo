#include "Particle.h"

Particle::Particle(const char* name, double mass, Vector p, Vector v, Vector a)
{
	_name = name;
	_mass = mass;
	_position = p;
	_velocity = v;
	_acceleration = a;
}

void Particle::Update(double dt)
{
	BaseUpdate(dt);
}