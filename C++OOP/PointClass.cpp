#include <iostream>
#include <cmath>
using namespace std;

class Point
{
	int x;
	int y;
	public:
	Point(){}
	Point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	
	int getX(){return x;}
	int getY(){return y;}
	void setX(int x){this->x = x;}
	void setY(int y){this->y = y;}
	
	double distance(Point p)
	{
		int a = this->getX() - p.getX();
		int b = this->getY() - p.getY();
		return sqrt(a*a + b*b);

	}
};
int main(){
	Point p1 ={2,3};
	Point p2;
	int x2,y2;
	
	cin>>x2;
	cin>>y2;

	p2 = {x2,y2};
	
	cout<<p1.getX()<<","<<p1.getY()<<endl;
	cout<<p2.getX()<<","<<p2.getY()<<endl;

	cout<<"Distance between the 2 points is "<<p1.distance(p2)<<endl;
	

	


}

