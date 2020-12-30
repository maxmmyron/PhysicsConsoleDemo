#pragma once

#include "Vector.h"
#include "Object.h"

class Particle : public Object
{
public:
	/*************************
		Constructors
	*************************/
	Particle() = default;
	Particle(const char*, float, Vector, Vector, Vector, bool doUpdates = true, bool debug = false);

	/*************************
		Update
	*************************/
	void Update(double);
	
	/*************************
		Debug
	*************************/
	void DebugPrintState();
};

