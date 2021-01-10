#include <Engine.h>
#include <Particle.h>

#include <Polygon.h>

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

	GameObject::MovementData md1 = { Vector(10,0), Vector(1, 0), Vector() };
	PhysicsEngine::Polygon::PolygonData pd1 = { 5, {Vector(3,5), Vector(6,3), Vector(4,1), Vector(2,2), Vector(1,4)}, {1} };
	PhysicsEngine::Polygon p = PhysicsEngine::Polygon("Polygon A", 1.0f, md1, pd1);
}