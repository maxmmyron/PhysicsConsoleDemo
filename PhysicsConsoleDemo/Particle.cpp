#include "Particle.h"

/*************************
	Constructors
*************************/

Particle::Particle(const char* name, float mass, Vector pos, Vector vel, Vector accel, bool doUpdates, bool debug) {
	this->name = name;
	this->mass = mass;
	this->position = pos;
	this->velocity = vel;
	this->acceleration = accel;
	this->SetUpdatingStatus(doUpdates);
	this->SetDebuggingStatus(debug);
}

/*************************
	Update
*************************/
void Particle::Update(double dt)
{
	/*velocity = velocity + acceleration * dt;
	position = position + velocity * dt;

	std::cout << velocity.x + acceleration.x * dt << std::endl;
	std::cout << position.x + velocity.x * dt << std::endl;
	*/

	this->position += 1;

	std::cout << position.x << std::endl;

	if (IsDebugging())
	{
		DebugPrintState();
	}
	
}

/*************************
	Debug
*************************/
void Particle::DebugPrintState()
{
	std::cout << "Printing stats for particle \"" << name << "\":" << std::endl;
	
	std::cout << "mass: " << GetMass() << std::endl;
	
	std::cout << "pos_x: " << GetPosition().x << std::endl;
	std::cout << "pos_y: " << GetPosition().y << std::endl;

	std::cout << "vel_x: " << GetVelocity().x << std::endl;
	std::cout << "vel_y: " << GetVelocity().y << std::endl;

	std::cout << "accel_x: " << GetAcceleration().x << std::endl;
	std::cout << "accel_y: " << GetAcceleration().y << std::endl;
}