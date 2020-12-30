#pragma once

#include <Vector.h>

class Object
{
public:
	/*************************
		Constructors
	*************************/
	Object() = default;
	/*************************
		Particle Information
	*************************/
	const char* name = NULL;

	/*************************
		Particle Manipulation
	*************************/
	void DestroySelf();

	/*************************
		Getters & Setters
	*************************/
	bool ToDestroy();

	bool IsUpdating();
	void SetUpdatingStatus(bool);

	bool IsDebugging();
	void SetDebuggingStatus(bool);

	double GetMass();
	void SetMass(double);

	Vector GetPosition();
	void SetPosition(Vector);

	Vector GetVelocity();
	void SetVelocity(Vector);

	Vector GetAcceleration();
	void SetAcceleration(Vector);

private:
	bool doUpdates = true;
	bool debugging = false;
	bool _doDestroy = false;
protected:
	Vector position;
	Vector velocity;
	Vector acceleration;

	double mass = 1.0;
};

