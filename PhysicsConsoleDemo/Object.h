#pragma once

#include <Vector.h>
#include <Engine.h>

class Object
{
public:
	/*************************
		Getters & Setters
	*************************/
	bool IsDebugging();
	void SetDebugging(bool);

	const char* GetName();

	double GetMass();
	void SetMass(double);

	Vector GetPosition();
	void SetPosition(Vector);

	Vector GetVelocity();
	void SetVelocity(Vector);

	Vector GetAcceleration();
	void SetAcceleration(Vector);

private:
	const char* name = NULL;
	double mass = 1.0;
	Vector position;
	Vector velocity;
	Vector acceleration;

	Engine engine;
	bool doUpdates = true;
	bool debugging = false;
};

