#include "Object.h"
#include <Vector.h>

/*************************
	Getters & Setters
*************************/
bool Object::IsDebugging()
{
	return debugging;
}
void Object::SetDebugging(bool b)
{
	debugging = b;
}

const char* Object::GetName()
{
	return name;
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