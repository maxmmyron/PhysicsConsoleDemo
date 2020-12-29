// PhysicsConsoleDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Particle.h>
#include <Vector.h>
#include <Engine.h>

#include <type_traits>
#include <iterator>

#include<File.h>

//issues:
//doesn't print correct stats after loop has ended
//doesn't run true to time (lags behind)

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
	std::cout << "Elapsed Time: " << e.GetTime() << "s"<< std::endl;
}

int main()
{
	Particle p1 = Particle("Particle A", 3.0f, Vector(), Vector(1, 0), Vector());
	Particle p2 = Particle("Particle B", 3.0f, Vector(), Vector(), Vector(1, 0));

	p1.SetPrintStatsValue(true);

	e.Add(p1);
	e.Add(p2);

	e.InitLoop();
}