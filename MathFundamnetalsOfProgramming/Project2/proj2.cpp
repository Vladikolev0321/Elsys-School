#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

class Point
{
public:
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
///To add Ball class
class Table
{
	vector<Point> points;
	int count_points;
public:
	Table()
	{
		count_points = 0;
	};
	void add_point(Point p)
	{
		this->points.push_back(p);
		count_points++;
	}
	void print_points()
	{
		for (list<Point>::iterator it = this->points.begin(); it != this->points.end(); it++)
		{
			Point curr_point = *it;
			cout << curr_point.x << ',' << curr_point.y <<endl;
		}
	}
	int check_if_rectangle()
	{
		int first_length = sqrt( pow(points[2].x - points[1].x, 2) + pow(points[2].y - points[1].y, 2);
		int second_length = sqrt( pow(points[4].x - points[3].x, 2) + pow(points[4].y - points[3].y, 2);

		int first_width = sqrt( pow(points[2].x - points[1].x, 2) + pow(points[2].y - points[1].y, 2);
		int second_width = sqrt( pow(points[4].x - points[3].x, 2) + pow(points[4].y - points[3].y, 2);
		
		if(first_length == second_length && first_width == second_width
		 && first_width * 2 == first_length)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
};
class Ball
{
	int x;
	int y;
	int diameter;
public:
	Ball(){};
	Ball(int x, int y, int diameter)
	{
		this->x = x;
		this->y = y;
		this->diameter = diameter;
	}
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	int get_diameter()
	{
		return diameter;
	}

};

void read_from_file(Table &table, Ball &ball)
{
	string file_name = "proj2.txt";

	ifstream istream;
	istream.open(file_name);

///coordinates of table

	string line1;
	getline(istream, line1);

	stringstream S(line1);

	for (int i = 0; i < 4; i++)
	{
		string curr_num_as_string;
		getline(S, curr_num_as_string, ',');
		int curr_num = stoi(curr_num_as_string);

		string curr_num_as_string2;
		getline(S, curr_num_as_string2, ' ');
		int curr_num2 = stoi(curr_num_as_string2);

		//cout << curr_num << ',' << curr_num2 <<endl;

		Point curr_point(curr_num, curr_num2);
		table.add_point(curr_point);
	}
//// to check if table is rectangle
/// func lenght of vector from 2 points
/// 
///diameter
	string line2;
	getline(istream, line2);

	stringstream S1(line2);
	string diameter_of_ball_as_string;
	getline(S1, diameter_of_ball_as_string, ' ');
	int diameter = stoi(diameter_of_ball_as_string);

////coordinates of ball
	string line3;
	getline(istream, line3);

	stringstream S3(line3);

	string x_as_string;
	getline(S3, x_as_string, ',');
	int x_coordinate = stoi(x_as_string);

	string y_as_string;
	getline(S3, y_as_string, ' ');
	int y_coordinate = stoi(y_as_string);

	ball = Ball(x_coordinate, y_coordinate, diameter);
	//for()
}
void write_to_file()
{
	string file_name = "proj2.txt";

	ofstream ostream;
	ostream.open(file_name);

	string table_coorrdinates;
	getline(cin, table_coorrdinates);
	//cin>>table_coorrdinates;

	string diameter_of_ball;
	getline(cin, diameter_of_ball);
	//cin>>diameter_of_ball;

	string ball_coordinates;
	getline(cin, ball_coordinates);
	//cin>>ball_coordinates;


	ostream << table_coorrdinates << endl;
	ostream << diameter_of_ball << endl;
	ostream<<ball_coordinates << endl;

	ostream.close();
}
int main()
{
	/*
	0,0 320,0 320,160 0,160
	0
	280,70
	*/
	cout<<"Do you want to change the coordinates:(yes/no)"<<endl;
	string answer;
	getline(cin,answer);
	if(answer == "yes")
	{
		write_to_file();	
	}

	Table table;
	Ball ball;
	read_from_file(table, ball);


	//Printing Ball
	cout<<ball.get_x()<<endl;
	cout<<ball.get_y()<<endl;
	cout<<ball.get_diameter()<<endl;

	//Printing table
	//table.print_points();


	return 0;
}