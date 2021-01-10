#include "RPolygon.h"

using namespace PhysicsEngine;

/*************************
	Constructors
*************************/
RPolygon::RPolygon(const char* name, double mass, GameObject::MovementData& movementData, RPolygonData& rPolyData)
{
	_name = name;
	_mass = mass;
	_position = movementData.position;
	_velocity = movementData.velocity;
	_acceleration = movementData.acceleration;

	_radius = rPolyData.radius;
	_sides = rPolyData.sides;
	_restitution = rPolyData.objectArguments.restitution;
}

/*************************
	Update
*************************/
void RPolygon::Update(double dt)
{
	BaseUpdate(dt);
}

/*************************
	Getters & Setters
*************************/

double RPolygon::GetRPolyPerim()
{
	double sideLength = 2 * _radius * sin(GetCentralAngle() / 2);
	return sideLength * _sides;
}
double RPolygon::GetRPolyArea()
{
	return 0.5 * GetApothem() * GetRPolyPerim();
}
//Returns the length of a line from the center of a regular polygon to the midpoint of a side
double RPolygon::GetApothem()
{
	return _radius * cos(GetCentralAngle() / 2);
}
//Returns the central angle of a regular polygon (in radians).
double RPolygon::GetCentralAngle()
{
	return (M_PI * 2) / _sides;
}

double RPolygon::GetRadius()
{
	return _radius;
}
void RPolygon::setRadius(double r)
{
	_radius = r;
}