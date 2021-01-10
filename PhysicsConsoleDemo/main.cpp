#include <Engine.h>
#include <Particle.h>

#include <Polygon.h>

using namespace PhysicsEngine;

int main()
{
	Engine e = Engine();

	Particle::MovementData md1 = { Vector(10,0), Vector(1, 0), Vector() };
	Particle::MovementData md2 = { Vector(12,0), Vector(-1, 0), Vector() };

	Particle::ParticleArguments pa1 = { 1.0f, {1} };
	Particle::ParticleArguments pa2 = { 1.0f, {1} };

	Particle p1 = Particle("Particle A", 1.0f, md1, pa1);
	Particle p2 = Particle("Particle B", 1.0f, md2, pa2);

	e.AddParticle(&p1);
	e.AddParticle(&p2);

	e.StartLoop();

	std::cout << e.GetEngineTimeAsDouble() << std::endl;

	p1.DebugPrint();
	p2.DebugPrint();

}