#include "Object.h"
#include <Vector.h>

/*************************
	Object Manipulation
*************************/

void Object::DestroySelf()
{
	_doDestroy = true;
}

/*************************
	Getters & Setters
*************************/

bool Object::ToDestroy()
{
	return _doDestroy;
}

bool Object::IsUpdating()
{
	return doUpdates;
}
void Object::SetUpdatingStatus(bool b)
{
	doUpdates = b;
}

bool Object::IsDebugging()
{
	return debugging;
}
void Object::SetDebuggingStatus(bool b)
{
	debugging = b;
}

double Object::GetMass()
{
	return mass;
}
void Object::SetMass(double m)
{
	mass = m;
}

Vector Object::GetPosition()
{
	return position;
}
void Object::SetPosition(Vector p)
{
	position = p;
}

Vector Object::GetVelocity()
{
	return velocity;
}
void Object::SetVelocity(Vector v)
{
	velocity = v;
}

Vector Object::GetAcceleration()
{
	return acceleration;
}
void Object::SetAcceleration(Vector a)
{
	acceleration = a;
}