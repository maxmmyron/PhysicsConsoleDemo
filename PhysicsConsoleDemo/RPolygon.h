#pragma once

#include <Polygon.h>
#include <GameObject.h>

namespace PhysicsEngine
{
	class RPolygon : public Polygon
	{
	public:
		/*************************
			Structs
		*************************/
		struct RPolygonData
		{
			int sides;
			double radius;
			GameObject::ObjectArguments objectArguments;
		};

		/*************************
			Constructors
		*************************/
		RPolygon() = default;
		RPolygon(const char*, double, GameObject::MovementData&, RPolygonData&);

		/*************************
			Update
		*************************/
		void Update(double);

		/*************************
			Getters & Setters
		*************************/

		double GetRPolyPerim();
		double GetRPolyArea();
		double GetApothem();
		double GetCentralAngle();


		double GetRadius();
		void setRadius(double);

	protected:
		double _radius;
	private:
	};
}