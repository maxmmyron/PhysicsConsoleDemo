#include "Vector.h"
#include <math.h>

using namespace PhysicsEngine;

/*************************
	Constructor
*************************/
Vector::Vector()
{
	this->x = 0.0f;
	this->y = 0.0f;
}
Vector::Vector(double a)
{
	this->x = a;
	this->y = a;
}
Vector::Vector(double x, double y)
{
	this->x = x;
	this->y = y;
}

/*************************
	Vector Manipulation
*************************/
Vector Vector::operator+=(Vector v)
{
	this->x += v.x;
	this->y += v.y;
	return Vector(this->x, this->y);
}

Vector Vector::operator+=(double d)
{
	this->x += d;
	this->y += d;
	return Vector(this->x, this->y);
}

Vector Vector::operator-=(Vector v)
{
	this->x -= v.x;
	this->y -= v.y;
	return Vector(this->x, this->y);
}

Vector Vector::operator*=(double d)
{
	this->x *= d;
	this->y *= d;
	return Vector(this->x, this->y);
}

Vector Vector::operator+(Vector v)
{
	return Vector(this->x + v.x, this->y + v.y);
}

Vector Vector::operator-(Vector v)
{
	return Vector(this->x - v.x, this->y - v.y);
}

Vector Vector::operator*(double d)
{
	return Vector(this->x * d, this->y * d);
}

/*************************
	Vector Math
*************************/
double Vector::GetMagnitude()
{
	return sqrt(this->x + this->y);
}

double Vector::GetDotProduct(Vector v)
{
	return this->x * v.x + this->y * v.y;
}

double Vector::GetDistance(Vector v)
{
	return sqrt(pow(this->x - v.x, 2) + pow(this->y - v.y, 2));
}

/*************************
	Debug
*************************/
void Vector::PrintVector()
{
	std::cout << "x = " << this->x << std::endl;
	std::cout << "y = " << this->y << std::endl;
}