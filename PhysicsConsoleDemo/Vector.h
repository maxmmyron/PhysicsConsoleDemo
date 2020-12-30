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
	double getMagnitude();
	
	double getDotProduct(Vector);

	/*************************
		Debug
	*************************/
	void print();
};

