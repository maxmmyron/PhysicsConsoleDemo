#include "Engine.h"

Engine::Engine() {}

//Runs the main Engine Loop.
void Engine::StartLoop()
{
	using namespace std::chrono_literals;
	using clock = std::chrono::high_resolution_clock;
	using ns = std::chrono::nanoseconds;

	constexpr ns timestep(16000000ns);

	ns lag(0ns);

	auto time_prev = clock::now();
	engineTime = time_prev;

	while (isRunning)
	{
		auto time_now = clock::now();

		auto time_diff = time_now - time_prev;

		time_prev = time_now;

		lag += std::chrono::duration_cast<ns>(time_diff);

		double dt = std::chrono::duration_cast<std::chrono::duration<double>>(time_diff).count();

		if (lag >= timestep)
		{
			double divisor = std::chrono::duration_cast<std::chrono::duration<double>>(lag - lag % timestep).count();

			isRunning = HandleEvents();

			Update(divisor + dt);
			PostUpdate(divisor + dt);

			lag %= timestep;

			if (Engine::debugFunction != NULL) debugFunction();
		}
	}
}

//Manually stops the Engine loop
void Engine::StopLoop()
{
	isRunning = false;
}

//Adds a particle to the Engine so long as a Particle does not already exist with the desired name.
bool Engine::AddParticle(Particle* p)
{
	particleMap.insert(std::pair<const char*, Particle*>(p->GetName(), p));
	return true;
	/*for (auto it = particleMap.begin(); it != particleMap.end(); it++)
	{
		Particle &b = *it->second;
		if (b.GetName() == p->GetName())
		{
			return false;
		}
		else {
			particleMap.insert(std::pair<const char*, Particle*>(p->GetName(), p));
			return true;
		}
	}
	return false;*/
}

//Removes a particle from the Engine so long as the desired Particle exists. Returns true if removed.
bool Engine::RemoveParticle(Particle* p)
{
	particleMap.erase(p->GetName());
	return true;
	/*for (auto it = particleMap.begin(); it != particleMap.end(); it++)
	{
		Particle &b = *it->second;
		if (b.GetName() == p->GetName())
		{
			particleMap.erase(p->GetName());
			return true;
		}
	}
	return false;*/
}

//Removes a particle from the Engine so long as a Particle with the desired name exists. Returns true if removed.
bool Engine::RemoveParticle(const char* key)
{
	for (auto it = particleMap.begin(); it != particleMap.end(); it++)
	{
		Particle& b = *it->second;
		if (b.GetName() == key)
		{
			particleMap.erase(key);
			return true;
		}
	}
	return false;
}

//Returns a reference to a particle in the particleMap. If there is no such Particle with the desired key, a nullptr is returned.
Particle* Engine::GetParticle(const char* key)
{
	for (auto it = particleMap.begin(); it != particleMap.end(); it++)
	{
		Particle& b = *it->second;
		if (it->second->GetName() == key)
		{
			return particleMap.find(key)->second;
		}
	}
	return nullptr;
}

//Handles mouse and keyboard events and returns a bool to the Engine on whether to continue running.
bool Engine::HandleEvents()
{
	if (GetKeyState('A') & 0x8000) return false;
	return true;
}

//Runs an Update check for each GameObject in the game, and executes the appropriate response.
void Engine::Update(double dt)
{
	for (auto it = particleMap.begin(); it != particleMap.end(); it++)
	{
		Particle& p = *it->second;
		if (p._doDestroy)
		{
			RemoveParticle(&p);
		}
		else
		{
			if (p._doUpdates)
			{
				p.Update(dt);
			}
		}
	}
}

void Engine::PostUpdate(double dt)
{

}

double Engine::GetEngineTimeAsDouble()
{
	return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - Engine::engineTime).count();
}

std::chrono::steady_clock::time_point Engine::GetEngineTimePoint()
{
	return Engine::engineTime;
}