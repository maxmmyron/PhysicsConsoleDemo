#pragma once

#include <GameObject.h>
#include <vector>
#include <Vector.h>
#include <math.h>
#include <limits>

namespace PhysicsEngine
{
	class Polygon : public GameObject
	{
	public:
		/*************************
			Structs
		*************************/
		struct PolygonData
		{
			int sides;
			std::vector<Vector> points;
			ObjectArguments objectArguments;
		};

		/*************************
			Constructors
		*************************/
		Polygon() = default;
		Polygon(const char*, double, MovementData&, PolygonData&);

		/*************************
			Update
		*************************/
		void Update(double);

		/*************************
			Polygon Info
		*************************/
		bool IsConvex();
		std::vector<Vector> GetBoundingBoxPoints();

		/*************************
			Collision Detection
		*************************/
		bool SATCollision(Polygon&);

		/*************************
			Getters & Setters
		*************************/
		double GetPolyPerim();
		double GetPolyArea();

		double GetSides();
		void SetSides(int);

		std::vector<Vector> GetPoints();
		void SetPoints(std::vector<Vector>);
	protected:
		int _sides;
		std::vector<Vector> _points;
	private:
		double ConvexCrossProduct(double, double, double, double, double, double);
	};
}