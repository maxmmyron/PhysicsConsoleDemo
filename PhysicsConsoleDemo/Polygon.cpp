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
	Polygon Info
*************************/
bool Polygon::IsConvex()
{
	std::vector<Vector> boundingPoints = GetBoundingBoxPoints();

	bool neg = false;
	bool pos = false;
	int n = _points.size();
	for (int i = 0; i < n; i++) {
		int a = i;
		int b = (i + 1) % n;
		int c = (i + 2) % n;
		double crossProduct = ConvexCrossProduct(_points[a].x, _points[a].y, _points[b].x, _points[b].y, _points[c].x, _points[c].y);
		if (crossProduct < 0) neg = true;
		else if (crossProduct > 0) pos = true;
		if (neg && pos) return false;
	}
	return true;
}

double Polygon::ConvexCrossProduct(double ax, double ay, double bx, double by, double cx, double cy) {
	double BAx = ax - bx;
	double BAy = ay - by;
	double BCx = cx - bx;
	double BCy = cy - by;
	return (BAx * BCy - BAy * BCx);
}

std::vector<Vector> Polygon::GetBoundingBoxPoints()
{
	Vector v1 = _points[0], v2 = _points[0];
	for (Vector& v : _points)
	{
		if (v.x < v1.x)
		{
			v1.x = v.x;
		}
		if (v.x > v2.x)
		{
			v2.x = v.x;
		}

		if (v.y < v1.y)
		{
			v1.y = v.y;
		}
		if (v.y > v2.y)
		{
			v2.y = v.y;
		}
	}
	return {v1, v2};
}
/*************************
	Collision Detection
*************************/

// Shamelessly ripped from https://gist.github.com/nyorain/dc5af42c6e83f7ac6d831a2cfd5fbece
// Credit to @nyorain for his SAT implementation!
bool Polygon::SATCollision(Polygon& p)
{
	for (unsigned int i = 0; i < _points.size(); i++)
	{
		// create an edge through two verticies
		Vector curr = _points[i];
		Vector next = _points[(i + i) % _points.size()];
		Vector edge = next - curr;

		Vector axis(-edge.y, edge.x);
		axis.PrintVector();

		// loop over all vertices of both polygons and project them
		// onto the axis. We are only interested in max/min projections
		auto aMaxProj = -std::numeric_limits<float>::infinity();
		auto aMinProj = std::numeric_limits<float>::infinity();
		auto bMaxProj = -std::numeric_limits<float>::infinity();
		auto bMinProj = std::numeric_limits<float>::infinity();

		// loop through verticies on poly A
		for (Vector& v : _points)
		{
			double projection = axis.GetDotProduct(v);
			if (projection < aMinProj) aMinProj = projection;
			if (projection > aMaxProj) aMaxProj = projection;
		}

		// loop through verticies on poly B
		for (Vector& v : p._points)
		{
			double projection = axis.GetDotProduct(v);
			if (projection < bMinProj) bMinProj = projection;
			if (projection > bMaxProj) bMaxProj = projection;
		}

		// now check if the intervals the both polygons projected on the
		// axis overlap. If they don't, we have found an axis of separation and
		// the given polygons cannot overlap
		if (aMaxProj < bMinProj || aMinProj > bMaxProj) {
			return false;
		}
	}
	// at this point, we have checked all axis but found no separating axis
	// which means that the polygons must intersect.
	return true;
}

/*************************
	Getters & Setters
*************************/
double Polygon::GetPolyPerim()
{
	double p = 0.0;
	for (unsigned int i = 0; i < _points.size(); i++)
	{
		p += _points[i].GetDistance(_points[(i + 1) % _points.size()]);
	}
	return p;
}

double Polygon::GetPolyArea()
{
	double a = 0;
	for (unsigned int i = 0; i < _points.size(); i++)
	{
		double avgHeight = (_points[i].y + _points[(i+1) % _points.size()].y) / 2;
		a += avgHeight * (_points[(i + 1) % _points.size()].x - _points[i].x);
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