#pragma once

#include "Vector.h"
#include "Engine.h"
#include "Object.h"

class Particle : public Object
{
public:
	/*************************
		Constructors
	*************************/
	Particle() = default;
	Particle(const char*, float, Vector, Vector, Vector, bool doUpdates = true);

	/*************************
		Particle Information
	*************************/
	void SetEngine(Engine);

	/*************************
		Particle Manipulation
	*************************/
	void DestroySelf();

	void PauseUpdates();
	void ResumeUpdates();
	bool IsUpdating();

	/*************************
		Update
	*************************/
	void Update(double);
	
	/*************************
		Debug
	*************************/
	void DebugPrintState();

	/*************************
		Getters & Setters
	*************************/
	bool GetPrintStatsValue();
	void SetPrintStatsValue(bool);

	const char* getName();

	float getMass();
	void setMass(float);

	Vector getPosition();
	void setPosition(Vector);

	Vector getVelocity();
	void setVelocity(Vector);

	Vector getAcceleration();
	void setAcceleration(Vector);

private:
	const char* name = NULL;
	float mass = 1.0f;
	Vector position;
	Vector velocity;
	Vector acceleration;

	Engine engine;
	bool doUpdates = true;
	bool PrintStats = false;
};

