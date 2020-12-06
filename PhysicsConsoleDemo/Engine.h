#pragma once

#include <iostream>
#include<Particle.h>
#include<vector>

class Engine
{
public:
	/*************************
		Public Variables
	*************************/
	bool running = true;
	double Time = 0.0;



	/*************************
		Constructor
	*************************/
	Engine();

	/*************************
		Loop Function
	*************************/
	struct State
	{
		std::vector<Particle> ParticleArray;
	} GameState;

	/*************************
		Loop Init Function
	*************************/
	void InitLoop();

	void Add(Particle);

private:

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

