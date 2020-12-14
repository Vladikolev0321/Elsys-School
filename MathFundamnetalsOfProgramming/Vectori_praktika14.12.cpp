#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
	double x;
	double y;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

};
class Vector{
	double x;
	double y;
public:
	Vector(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Vector(Point first, Point second)
	{
		this->x = second.x - first.x;
		this->y = second.y - first.y;
	}
	void sum(const Vector& other)const
	{
		cout << "(" << x << ", " << y << ")" << "("<< other.x << ", " <<other.y << ")" <<" = ";
		cout << "(" << x + other.x << ", " << y + other.y << ")" <<endl;
	}
	void difference(const Vector& other)
	{
		cout << "(" << x << ", " << y << ")" << "("<< other.x << ", " <<other.y << ")" <<" = ";
		cout << "(" << x - other.x << ", " << y - other.y << ")" <<endl;
	}

	Vector operator+(const Vector& other)const
	{
		return Vector(x+other.x, y+other.y);
	}
	Vector operator-()const
	{
		return Vector(-x, -y);
	}
	Vector operator-(const Vector& other) const
	{
		return *this - other;
	}
	bool is_colinear(const Vector& other) const
	{
		return x/y == other.x/other.y;
	}
	double length() const
	{
		return sqrt(x*x + y*y);
	}
	double angle(const Vector& other) const
	{
		double dotPed = x * other.x + y*other.y;
		double angleCos = (dotPed / (this->length() * other.length()));
		return acos(angleCos);
	}
};
double area(const Point& p1, const Point& p2, const Point& p3)
{
	return 0.5 * abs((p2.x - p1.x) *(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y));
}
/*double area(const Point points[50], int size)
{
	if(size < 3)
	{

	}
}
*/
int main()
{
	Vector v1 = Vector(Point(0,0), Point(3, 5));
	Vector v2 = Vector(Point(3,5), Point(7, 3));

}