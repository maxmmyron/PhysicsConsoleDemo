#include <iostream>
#pragma once
class Vector
{
public:
	float x;
	float y;

	/*************************
		Constructor
	*************************/
	Vector();
	Vector(float, float);

	/*************************
		Vector Manipulation
	*************************/
	Vector operator+=(Vector);
	Vector operator-=(Vector);
	Vector operator*=(float);

	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(float);

	/*************************
		Vector Math
	*************************/
	float getMagnitude();
	
	float getDotProduct(Vector);

	/*************************
		Debug
	*************************/
	void print();
};

