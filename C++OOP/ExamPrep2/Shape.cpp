#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual int get_area()const
    {
        return 0;
    }
    virtual int get_perimeter()const
    {
        return 0;
    }
};
class Square : public Shape
{
    int a;
public:
    Square(int a)
    {
        this->a = a;
    }
    int get_area()const override
    {
        return a*a;
    }
    int get_perimeter()const override
    {
        return 4*a;
    }
};
class Rectangle : public Shape
{
    int a,b;
public:
    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int get_area()const override
    {
        return pow((a+b), 2);
    }
    int get_perimeter()const override
    {
        return 2*(a+b);
    }
};

void print_area_and_shape(const Shape& s)
{
    cout<<"Peimeter: "<< s.get_perimeter() << "Area: "<< s.get_area()<<endl;
}

int main()
{
    Shape sh1;
    print_area_and_shape(sh1);
    Square sh2 = Square(2);
    print_area_and_shape(sh2);
    Rectangle sh3(2, 3);
    print_area_and_shape(sh3);

}