// PhysicsConsoleDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Particle.h>
#include <Vector.h>
#include <Engine.h>

#include <type_traits>
#include <iterator>

template<typename T>
void debugPrintList(std::vector<T> arr)
{
	for (typename std::vector<T>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << it->name << std::endl;
	}
}

Engine e = Engine();

void debugEx()
{
	std::cout << "Elapsed Time: " << e.getTime() << "s"<< std::endl;
}

int main()
{
	Particle p1("Particle A", 3.0f, Vector(), Vector(1, 0), Vector());

	e.Add(p1);

	e.debugFunction = debugEx;

	e.InitLoop();
}