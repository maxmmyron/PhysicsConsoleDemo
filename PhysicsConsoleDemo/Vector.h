#include <iostream>
#pragma once
class Vector
{
public:
	double x;
	double y;

	/*************************
		Constructor
	*************************/
	Vector();
	Vector(double);
	Vector(double, double);

	/*************************
		Vector Manipulation
	*************************/
	Vector operator+=(Vector);
	Vector operator+=(double);
	Vector operator-=(Vector);
	Vector operator*=(double);

	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(double);

	/*************************
		Vector Math
	*************************/
	double GetMagnitude();
	
	double GetDotProduct(Vector);

	double GetDistance(Vector);

	/*************************
		Debug
	*************************/
	void PrintVector();
};

