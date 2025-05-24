#pragma once
#include <iostream>

using namespace std;


class Shape
{
	string type;
	float x, y;

public:
	Shape(string type, float x, float y) : type(type), x(x), y(y) { }
	virtual ~Shape() {}
	virtual float area() = 0;
	virtual void info()
	{
		cout << "Type : " << type << ", (" << x << ", " << y << ")" << endl;
	}
};

class Circle : public Shape
{
	float radius;

public:
	Circle(float x, float y, float radius) : radius(radius), Shape("Circle", x, y) {}
	virtual float area() override
	{
		return 3.1415192 * radius * radius;
	}

	virtual void info() override
	{
		Shape::info();
		cout << "Radius : " << radius << endl;
	}
};
