#include "Polygon.h"

using namespace PhysicsEngine;

//TODO : return error (or -1?) for PolyArea if Polygon shape is complex, or throw error if the shape is complex in the first place on instantiation.

/*************************
	Constructors
*************************/
Polygon::Polygon(const char* name, double mass, MovementData& movementData, PolygonData& polyData)
{
	_name = name;
	_mass = mass;
	_position = movementData.position;
	_velocity = movementData.velocity;
	_acceleration = movementData.acceleration;

	_sides = polyData.sides;
	_points = polyData.points;
	_restitution = polyData.objectArguments.restitution;
}

/*************************
	Update
*************************/
void Polygon::Update(double dt)
{
	BaseUpdate(dt);
}

/*************************
	Getters & Setters
*************************/

double Polygon::GetPolyPerim()
{
	double p = 0.0;
	for (unsigned int i = 0; i < _points.size(); i++)
	{
		if (i == _points.size() - 1)
		{
			p += _points[i].GetDistance(_points[0]);
			break;
		}
		else
		{
			p += _points[i].GetDistance(_points[i + 1]);
		}
		
	}
	return p;
}

double Polygon::GetPolyArea()
{
	double a = 0;
	for (unsigned int i = 0; i < _points.size(); i++)
	{
		if (i == _points.size() - 1)
		{
			double avgHeight = (_points[i].y + _points[0].y) / 2;
			a += avgHeight * (_points[0].x - _points[i].x);
			break;
		}
		else
		{
			double avgHeight = (_points[i].y + _points[i + 1].y) / 2;
			a += avgHeight * (_points[i + 1].x - _points[i].x);
		}
	}
	return a;
}

double Polygon::GetSides()
{
	return _sides;
}
void Polygon::SetSides(int s)
{
	_sides = s;
}

std::vector<Vector> Polygon::GetPoints()
{
	return _points;
}
void Polygon::SetPoints(std::vector<Vector> p)
{
	_points = p;
}