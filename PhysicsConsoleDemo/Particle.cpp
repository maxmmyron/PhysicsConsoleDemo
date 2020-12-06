#include "Particle.h"

/*************************
	Constructors
*************************/
Particle::Particle(const char *name, float mass, Vector pos, Vector vel, Vector accel){
	this->name = name;
	this->mass = mass;
	this->pos = pos;
	this->vel = vel;
	this->accel = accel;
}

/*************************
	Particle Manipulation
*************************/

/*************************
	Update
*************************/
void Particle::update(double dt)
{
	//not sure the right way to order this.
	vel += (accel * dt);
	pos += (vel * dt);

	printStats();
}

/*************************
	Debug
*************************/
void Particle::printStats()
{
	std::cout << "Printing stats for particle \"" << name << "\":" << std::endl;
	
	std::cout << "mass: " << mass << std::endl;
	
	std::cout << "vel_x: " << vel.x << std::endl;
	std::cout << "vel_y: " << vel.y << std::endl;

	std::cout << "accel_x: " << accel.x << std::endl;
	std::cout << "accel_y: " << accel.y << std::endl;

	std::cout << "pos_x: " << pos.x << std::endl;
	std::cout << "pos_y: " << pos.y << std::endl;
}