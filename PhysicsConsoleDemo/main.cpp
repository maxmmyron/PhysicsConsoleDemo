#include <Engine.h>
#include <Particle.h>

#include <Polygon.h>

using namespace PhysicsEngine;

int main()
{
	/*Engine e = Engine();

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
	p2.DebugPrint();*/

	Particle::MovementData md1 = { 0, 0, 0 };

	Polygon::PolygonData pd1 = { 3, {Vector(1,1), Vector(1,2), Vector(2,2)}, {1} };
	Polygon::PolygonData pd2 = { 3, {Vector(3,3), Vector(3,4), Vector(4,4)}, {1} };

	PhysicsEngine::Polygon a("a", 1, md1, pd1);
	PhysicsEngine::Polygon b("a", 1, md1, pd2);


	std::cout << a.SATCollision(b) << std::endl;
	std::cout << b.SATCollision(a) << std::endl;
}