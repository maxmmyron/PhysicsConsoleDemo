#pragma once

#include <Particle.h>
#include <iostream>
#include <map>
#include <vector> 
#include <chrono>
#include <iterator>
#include <Windows.h>

namespace PhysicsEngine
{
	class Engine
	{
	public:
		/*************************
			Public Variables
		*************************/
		bool isRunning = true;

		void (*debugFunction)() = NULL;

		std::map<const char*, Particle*> particleMap;

		/*************************
			Constructor
		*************************/
		Engine();

		/*************************
			Loop Functions
		*************************/
		void StartLoop();
		void StopLoop();

		/*************************
			Map Functions
		*************************/
		bool AddParticle(Particle*);
		bool RemoveParticle(Particle*);
		bool RemoveParticle(const char*);
		Particle* GetParticle(const char*);

		/*************************
			Getters & Setters
		*************************/
		double GetEngineTimeAsDouble();
		std::chrono::steady_clock::time_point GetEngineTimePoint();

	private:
		/*************************
			Private Variables
		*************************/
		std::chrono::steady_clock::time_point engineTime;

		/*************************
			Handler Functions
		*************************/
		bool HandleEvents();

		/*************************
			Update Functions
		*************************/
		void Update(double);
		void PostUpdate(double);
	};
}