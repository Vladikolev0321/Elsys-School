#include <iostream>
#include <math.h>
using namespace std;
class Shape
{
public:
	virtual double get_perimeter()const
	{
		return 0;
	}
	virtual double get_area()const
	{
		return 0;
	}
};
class Square:public Shape
{
	double side;
public:
	Square(double side)
	{
 		this->side = side;
	}
	double get_perimeter()const override
	{
		return side*4;
	}
	double get_area()const override
	{
		return side*side;
	}

};
class Rectangle:public Shape
{
	double width;
	double height;
public:
	Rectangle(double width, double height)
	{
		this->width = width;
		this->height = height;
	}
	double get_perimeter()const override
	{
		return 2*(width+height);
	}
	double get_area()const override
	{
		return width*height;
	}
};
class Circle:public Shape
{
	double radius;
public:
	Circle(double radius)
	{
		this->radius = radius;
	}
	double get_perimeter()const override
	{
		return 2*M_PI*radius;
	}
	double get_area()const override
	{
		return M_PI*radius*radius;
	}

};
void print_area_and_shape(const Shape& s)
{
	cout<<"Perimeter: "<<s.get_perimeter()<<endl;
	cout<<"Area: "<<s.get_area()<<endl;
}
int main()
{
	Square square(2);
	print_area_and_shape(square);

	Rectangle rectangle(2,3);
	print_area_and_shape(rectangle);

	Circle circle(2);
	print_area_and_shape(circle);
}