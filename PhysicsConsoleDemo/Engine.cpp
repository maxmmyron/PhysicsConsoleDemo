#include "Engine.h"

#include <iostream>
#include <iomanip>

#include <chrono>
#include <Windows.h>

#include <Particle.h>
#include <vector>
#include <File.h>

#include <map>

#include <thread>

/*************************
	Constructor
*************************/
Engine::Engine()
{
	Engine::_p = nullptr;
}

/*************************
	Game State Manipulators
*************************/

void Engine::Add(Particle p)
{
	GameState.ParticleMap.insert(std::pair<const char*, Particle>(p.getName(), p));
}

void Engine::Remove(const char* name)
{
	GameState.ParticleMap.erase(name);
}

/*************************
	Loop
*************************/

//Loop Initializer
using namespace std::chrono_literals;
void Engine::InitLoop()
{
	std::thread LoopThread(&Engine::Loop, this);

	LoopThread.join();
}

void Engine::Loop()
{
	char buffer[32];
	//Loss in data here from _Rep to int
	int time = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now()).time_since_epoch().count();
	snprintf(buffer, sizeof(char) * 32, "debug%i.csv", time);
	std::cout << buffer << std::endl;
	const char* fName = buffer;
	File f(buffer, std::ios::in | std::ios::out | std::ios::trunc);
	if (f.IsOpen)
	{
		f.Write<const char*>("Time, Pos, Offset, Percent, Lag", true);
	}

	using clock = std::chrono::high_resolution_clock;
	using ns = std::chrono::nanoseconds;

	constexpr ns timestep(16000000ns);

	ns lag(0ns);

	//Get a time for right now
	auto t_prev = clock::now();
	Engine::time = t_prev;

	bool running = true;

	//quite jank, but should do for now.
	int n = 0;
	while (running)
	{
		auto t_now = clock::now();
		//delta_t is equal to the change in time.
		auto dt = t_now - t_prev;
		//reset t
		t_prev = t_now;

		lag += std::chrono::duration_cast<ns>(dt);

		//return bool after we run Handler Events.
		running = HandleEvents();

		//Get a double value for delta_t. this is elasped time since last update call.
		double dt_double = std::chrono::duration_cast<std::chrono::duration<double>>(dt).count();

		//check if lag is greater than the preferred timestep. if so, then update and let lag value assume remainder of lag % timestep.
		if (lag >= timestep)
		{
			double divisor = std::chrono::duration_cast<std::chrono::duration<double>>(lag - (lag % timestep)).count();
			Update(dt_double + divisor);
			PostUpdate(dt_double + divisor);
			lag %= timestep;

			if (f.IsOpen)
			{
				f.Write<double>(std::chrono::duration_cast<std::chrono::duration<double>>(clock::now() - Engine::time).count(), false);
				f.Write<const char*>(", ", false);
				f.Write<float>(Engine::GameState.ParticleMap.find("Particle A")->second.getPosition().x, false);
				f.Write<const char*>(", ", false);
				f.Write<double>(std::chrono::duration_cast<std::chrono::duration<double>>(clock::now() - Engine::time).count() - Engine::GameState.ParticleMap.find("Particle A")->second.getPosition().x, false);
				f.Write<const char*>(", ", false);
				f.Write<double>(Engine::GameState.ParticleMap.find("Particle A")->second.getPosition().x / std::chrono::duration_cast<std::chrono::duration<double>>(clock::now() - Engine::time).count(), false);
				f.Write<const char*>(", ", false);
				f.Write<double>(std::chrono::duration_cast<std::chrono::duration<double>>(lag).count(), false);
				f.Write<const char*>(",", true);
			}

			if (Engine::debugFunction != NULL) debugFunction();
		}
	}
	f.Close();
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
		(it)->second.Update(dt);
	}
}
void Engine::PostUpdate(double dt)
{

}

/*************************
	Getters & Setters
*************************/

double Engine::GetTime()
{
	auto now_ms = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - Engine::time);
	return now_ms.count();
}

Particle Engine::GetParticleFromParticleMap(const char* particleName)
{
	return GameState.ParticleMap[particleName];
}