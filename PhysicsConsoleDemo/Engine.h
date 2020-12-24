#pragma once

#include <iostream>
#include <Particle.h>
#include <vector>
#include <chrono>
#include <map>

class Engine
{
public:
	/*************************
		Public Variables
	*************************/
	bool running = true;

	void (*debugFunction)() = NULL;

	/*************************
		Constructor
	*************************/
	Engine();

	/*************************
		Loop Function
	*************************/
	struct State
	{
		std::map<const char*, Particle> ParticleMap;
	} GameState;

	/*************************
		Loop Init Function
	*************************/
	void InitLoop();

	void Add(Particle);

	/*************************
		Return Function
	*************************/
	double getTime();

	Particle getParticleFromParticleMap(const char*);

private:
	/*************************
		Private Variables
	*************************/
	std::chrono::steady_clock::time_point time;

	/*************************
		Handler Functions
	*************************/
	bool HandleEvents();

	/*************************
		Update Functions
	*************************/
	void Update(double);
	void PostUpdate(double);

	/*************************
		Loop Function
	*************************/
	void Loop();
};

