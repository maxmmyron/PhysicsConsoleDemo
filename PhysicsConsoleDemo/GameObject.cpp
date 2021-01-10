#include "GameObject.h"

using namespace PhysicsEngine;

/*************************
	Base Update
*************************/

void GameObject::BaseUpdate(double dt)
{
	_velocity += _acceleration * dt;
	_position += _velocity * dt;
}

/*************************
	Getters & Setters
*************************/

const char* GameObject::GetName()
{
	return _name;
}


double GameObject::GetMass()
{
	return _mass;
}
void GameObject::SetMass(double mass)
{
	_mass = mass;
}

Vector GameObject::GetPosition()
{
	return _position;
}
void GameObject::SetPosition(Vector p)
{
	_position = p;
}

Vector GameObject::GetVelocity()
{
	return _velocity;
}
void GameObject::SetVelocity(Vector v)
{
	_velocity = v;
}

Vector GameObject::GetAcceleration()
{
	return _acceleration;
}
void GameObject::SetAcceleration(Vector a)
{
	_acceleration = a;
}

void GameObject::DebugPrint()
{
	std::cout << "------------" << std::endl;

	std::cout << "Printing out statistics for object \"" << _name << "\": " << std::endl;

	std::cout << "mass: " << _mass << std::endl;

	std::cout << "pos x: " << _position.x << std::endl;
	std::cout << "pos y: " << _position.y << std::endl;

	std::cout << "vel x: " << _velocity.x << std::endl;
	std::cout << "vel y: " << _velocity.y << std::endl;

	std::cout << "acc x: " << _acceleration.x << std::endl;
	std::cout << "acc y: " << _acceleration.y << std::endl;

	std::cout << "restitution: " << _restitution << std::endl;
}