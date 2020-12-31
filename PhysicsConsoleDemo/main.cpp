// PhysicsConsoleDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Particle.h>
#include <Vector.h>
#include <Engine.h>

#include <type_traits>
#include <iterator>

#include<File.h>

Engine e = Engine();

int main()
{
	Particle p1 = Particle("Particle A", 3.0f, Vector(), Vector(1, 0), Vector());
	Particle p2 = Particle("Particle B", 3.0f, Vector(), Vector(), Vector(1, 0));

	e.AddParticle(&p1);
	e.AddParticle(&p2);
	
	e.StartLoop();

	std::cout << e.GetEngineTimeAsDouble() << std::endl;

	p1.DebugPrint();
	p2.DebugPrint();
}