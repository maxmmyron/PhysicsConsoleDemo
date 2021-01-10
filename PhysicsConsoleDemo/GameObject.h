#pragma once

#include <iostream>
#include <Vector.h>

class GameObject
{
public:

	struct ObjectArguments
	{
		double restitution;
	};

	struct MovementData
	{
		Vector position;
		Vector velocity;
		Vector acceleration;
	};

	/*************************
		Getters & Setters
	*************************/
	const char* GetName();

	double GetMass();
	void SetMass(double);

	Vector GetPosition();
	void SetPosition(Vector);

	Vector GetVelocity();
	void SetVelocity(Vector);

	Vector GetAcceleration();
	void SetAcceleration(Vector);

	/*************************
		Engine Flags
	*************************/
	bool _doUpdates = true;
	bool _doDebug = false;
	bool _doDestroy = false;

	/*************************
		Debug
	*************************/
	void DebugPrint();
protected:
	const char* _name;
	double _mass = 1.0;
	Vector _position = Vector();
	Vector _velocity = Vector();
	Vector _acceleration = Vector();
	double _restitution = 1.0;
	void BaseUpdate(double);
};

