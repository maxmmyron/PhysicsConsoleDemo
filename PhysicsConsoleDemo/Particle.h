#pragma once
#include <./Vector.h>
class Particle
{
public:
	/*************************
		Public Variables
	*************************/
	const char *name;
	float mass;
	Vector vel;
	Vector accel;
	Vector pos;

	/*************************
		Constructors
	*************************/
	Particle() = default;
	Particle(const char *, float, Vector, Vector, Vector);

	/*************************
		Particle Manipulation
	*************************/

	/*************************
		Update
	*************************/
	void update(double);

	/*************************
		Debug
	*************************/
	void printStats();

	
};

