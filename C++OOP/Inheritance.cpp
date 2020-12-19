#include <iostream>
#include <math.h>

using namespace std;
class Shape
{
public:
	virtual double get_area()const
	{
		return 0;
	}
	virtual double get_perimeter()const
	{
		return 0;
	}
};
class Square: public Shape
{
	double side;
public:
	Square(double side)
	{
		this->side = side;
	}
	double get_perimeter()const override 
	{
		return 4 * this->side;
	}
	double get_area()const override
	{
		return this->side*this->side;
	}
};
class Rectangle: public Shape
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
		return 2 * (this->width + this->height);
	}
	double get_area()const override
	{
		return this->width * this->height;
	}
};
class Circle: public Shape
{
	double radius;
public:
	Circle(int radius)
	{
		this->radius = radius;
	}
	double get_perimeter ()const override
	{
		return 2 * M_PI * this->radius;
	}
	double get_area()const override
	{
		return M_PI * this->radius * this->radius;
	}
};

void print_area_and_shape(const Shape& s)
{
	cout<<"Perimeter: "<<s.get_perimeter()<<endl;
	cout<<"Area: "<<s.get_area()<<endl;
}
int main()
{

	Square square = Square(2);
	print_area_and_shape(square);

	Rectangle rectangle = Rectangle(2,3);
	print_area_and_shape(rectangle);

	Circle circle = Circle(2);
	print_area_and_shape(circle);

}
