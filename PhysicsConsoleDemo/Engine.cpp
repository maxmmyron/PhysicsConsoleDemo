#include "Engine.h"

#include <iostream>
#include <iomanip>

#include <chrono>
#include <Windows.h>

#include <Particle.h>
#include <vector>

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
	auto s = t;
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
			Update(dt_double);
			PostUpdate(dt_double);
			lag %= timestep;	
		}
	}
}

/*************************
	Struct Functions
*************************/
void Engine::Add(Particle p)
{
	GameState.ParticleArray.push_back(p);
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
	for (typename std::vector<Particle>::iterator it = GameState.ParticleArray.begin(); it != GameState.ParticleArray.end(); it++)
	{
		it->update(dt);
	}
}
void Engine::PostUpdate(double dt)
{

}