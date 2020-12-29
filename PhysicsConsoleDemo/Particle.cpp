#include "Particle.h"
#include "Engine.h"

/*************************
	Constructors
*************************/

Particle::Particle(const char* name, float mass, Vector pos, Vector vel, Vector accel, bool doUpdates) {
	this->name = name;
	this->mass = mass;
	this->position = pos;
	this->velocity = vel;
	this->acceleration = accel;
	this->doUpdates = doUpdates;
}

/*************************
	Particle Informaton
*************************/
void Particle::SetEngine(Engine e)
{
	Particle::engine = e;
}

/*************************
	Particle Manipulation
*************************/

void Particle::DestroySelf()
{
	engine.Remove(this->getName());
}

void Particle::PauseUpdates()
{
	doUpdates = false;
}

void Particle::ResumeUpdates()
{
	doUpdates = true;
}

bool Particle::IsUpdating()
{
	return doUpdates;
}

/*************************
	Update
*************************/
void Particle::Update(double dt)
{
	//loss in data
	velocity += (acceleration * dt);
	//loss in data
	position += (velocity * dt);

	DebugPrintState();

	/*if (PrintStats)
	{
		
	}*/
	/*if (doUpdates) {
		
	}*/
}

/*************************
	Debug
*************************/
void Particle::DebugPrintState()
{
	std::cout << "Printing stats for particle \"" << name << "\":" << std::endl;
	
	std::cout << "mass: " << mass << std::endl;
	
	std::cout << "vel_x: " << velocity.x << std::endl;
	std::cout << "vel_y: " << velocity.y << std::endl;

	std::cout << "accel_x: " << acceleration.x << std::endl;
	std::cout << "accel_y: " << acceleration.y << std::endl;

	std::cout << "pos_x: " << position.x << std::endl;
	std::cout << "pos_y: " << position.y << std::endl;
}

/*************************
	Getters & Setters
*************************/
bool Particle::GetPrintStatsValue()
{
	return PrintStats;
}
void Particle::SetPrintStatsValue(bool b)
{
	PrintStats = b;
}

const char* Particle::getName()
{
	return name;
}

float Particle::getMass()
{
	return mass;
}
void Particle::setMass(float m)
{
	mass = m;
}

Vector Particle::getPosition() 
{
	return position;
}
void Particle::setPosition(Vector p)
{
	position = p;
}

Vector Particle::getVelocity()
{
	return velocity;
}
void Particle::setVelocity(Vector v)
{
	velocity = v;
}

Vector Particle::getAcceleration()
{
	return acceleration;
}
void Particle::setAcceleration(Vector a)
{
	acceleration = a;
}