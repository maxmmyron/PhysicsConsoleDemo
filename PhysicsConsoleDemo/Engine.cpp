#include "Engine.h"

#include <iostream>
#include <iomanip>

#include <chrono>
#include <Windows.h>

#include <Particle.h>
#include <vector>

#include<map>

#include <thread>

/*************************
	Constructor
*************************/
Engine::Engine()
{

}

/*************************
	Loop Init
*************************/

using namespace std::chrono_literals;
void Engine::InitLoop()
{	
	std::thread LoopThread(&Engine::Loop, this);

	LoopThread.join();
}

/*************************
	Loop Function
*************************/

void Engine::Loop()
{
	using clock = std::chrono::high_resolution_clock;

	constexpr std::chrono::nanoseconds timestep(16ms);

	std::chrono::nanoseconds lag(0ns);

	//Get a time for right now
	auto t = clock::now();
	//DEBUG: set extra variable to value of t. We reset the value of t later so we can't use it down the line.
	Engine::time = t;
	bool running = true;

	//quite jank, but should do for now.
	int n = 0;
	while (running)
	{
		//delta_t is equal to the change in time.
		auto dt = clock::now() - t;
		//reset t
		t = clock::now();

		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(dt);

		//return bool after we run Handler Events.
		running = HandleEvents();

		//Get a double value for delta_t. this is elasped seconds from last update call.
		double dt_double = std::chrono::duration_cast<std::chrono::duration<double>>(dt).count();

		//check if lag is greater than the preferred timestep. if so, then update and let lag value assume remainder of lag % timestep.
		if (lag >= timestep)
		{
			double divisor = std::chrono::duration_cast<std::chrono::duration<double>>(lag - (lag % timestep)).count();
			Update(dt_double + divisor);
			PostUpdate(dt_double + divisor);
			lag %= timestep;

			if (Engine::debugFunction != NULL) debugFunction();
		}
	}
}

/*************************
	Struct Functions
*************************/
void Engine::Add(Particle p)
{
	GameState.ParticleMap.insert(std::pair<const char*, Particle>(p.name, p));
}

/*************************
	Handler Functions
*************************/

bool Engine::HandleEvents()
{
	if (GetKeyState('A') & 0x8000) return false;
	return true;
}

/*************************
	Update Functions
*************************/
void Engine::Update(double dt)
{
	//Particle Phys Update
	for (typename std::map<const char*, Particle>::iterator it = GameState.ParticleMap.begin(); it != GameState.ParticleMap.end(); it++)
	{
		(it)->second.update(dt);
	}
}
void Engine::PostUpdate(double dt)
{

}

/*************************
	Return Functions
*************************/

double Engine::getTime()
{
	auto now_ms = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - Engine::time);
	return now_ms.count();
}

Particle Engine::getParticleFromParticleMap(const char* particleName)
{
	return GameState.ParticleMap[particleName];
}