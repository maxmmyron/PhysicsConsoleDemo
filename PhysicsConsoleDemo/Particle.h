#pragma once

#include <GameObject.h>
#include <Vector.h>

class Particle : public GameObject
{
public:
	Particle() = default;
	Particle(const char*, double, Vector, Vector, Vector);

	void Update(double);
};