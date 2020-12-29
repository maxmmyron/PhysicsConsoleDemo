#pragma once

#include <iostream>

//#include "Particle.h"
#include <vector>
#include <chrono>
#include <map>
#include <type_traits>

class Particle;

class Engine
{
	Particle* _p = nullptr;
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
		Game State & Manipulators
	*************************/
	struct State
	{
		std::map<const char*, Particle> ParticleMap;
	} GameState;

	void Add(Particle);
	void Remove(const char* key);

	/*************************
		Loop Init Function
	*************************/
	void InitLoop();

	/*************************
		Getters & Setters
	*************************/
	double GetTime();

	Particle GetParticleFromParticleMap(const char*);

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

