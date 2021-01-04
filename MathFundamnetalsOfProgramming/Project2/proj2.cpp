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
	double x;
	double y;
	Point(){};
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};
///To add Ball class
class Table
{
	int count_points;
public:
	vector<Point> points;
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
		for (vector<Point>::iterator it = this->points.begin(); it != this->points.end(); it++)
		{
			Point curr_point = *it;
			cout << curr_point.x << ',' << curr_point.y <<endl;
		}
	}
	void remove_points()
	{
		for (int i = 0; i < count_points; i++)
		{
			this->points.pop_back();
		}
		this->count_points = 0;
	}
	int check_if_rectangle()
	{
		int first_length = sqrt( pow(points[1].x - points[0].x, 2) + pow(points[1].y - points[0].y, 2) );
		int second_length = sqrt( pow(points[2].x - points[3].x, 2) + pow(points[2].y - points[3].y, 2) );

		int first_width = sqrt( pow(points[2].x - points[1].x, 2) + pow(points[2].y - points[1].y, 2) );
		int second_width = sqrt( pow(points[3].x - points[0].x, 2) + pow(points[3].y - points[0].y, 2) );
		

		///1 lenght and 1 width /// 
		/// ab||ox  ad || oy 2 points width0.y == width1.y width0.x != width1.x
		// 2 points lenght0.y != lenght3.y lenght0.x == length3.x
		// after that 
		// if ab !|| OX ad !||0X
		// y = ax + b    a-naklon(uglov koef)
		// a = (b1.y-a0.y)/(b1.x - a0.x) (pri ab)
		// calculate a for AD
		// aAB * aAD == -1 => AB perpendik AD

		if(first_length == second_length && first_width == second_width
		 && first_width * 2 == first_length)
		{
			if(points[0].y == points[1].y && points[0].x != points[1].x
				&& points[0].y != points[3].y && points[0].x == points[3].x)
			{
				return 1;
			}
			else
			{
				int koef1 = (points[1].y - points[0].y)/(points[1].x - points[0].x);
				int koef2 = (points[3].y - points[0].y)/(points[3].x - points[0].x);

				if(koef1 * koef2 == -1)
				{
					return 1;
				}
				else
				{
					this->remove_points();
					return 0;
				}
			}
		}
		else
		{
			this->remove_points();
			return 0;
		}

		///after that to move the ball
	}
};
class Ball
{
	double x;
	double y;
	double diameter;
	double start_x;
	double start_y;
public:
	Point direction;
	float strength;
	Ball(){};
	Ball(double x, double y, double diameter)
	{
		this->start_x = x;
		this->start_y = y;
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
	
	/////  max and min length of vector W/10 и W*3/10, w - length
	/////  min sila - 2  min length - 32
	////   pri pod sila - 2,5 , x length
	///2/2,5 = 32/x
	/// (32*2,5)/2 = x
	//length of vector with given sila x = (podsila*mindulj) / minsila

	/*double find_length_of_vector_which_the_ball_will_move(Table table)
	{
		double W = sqrt( pow(table.points[1].x - table.points[0].x, 2) + pow(table.points[1].y - table.points[0].y, 2) );
		//W/10
		//cout<<W<<endl;
		double min_length =  W/10;
		//cout<<min_length<<endl;
		double length_of_final_vector = (this->strength * min_length) / 2;

		return length_of_final_vector;
	}
	double find_length_of_direction_vector()
	{
		double length_of_direction_vector = sqrt( pow(direction.x - this->x, 2) + pow(direction.y - this->y, 2) );
		return length_of_direction_vector; 
	}
	void move(Table table)
	{
		double koef = find_length_of_direction_vector() / find_length_of_vector_which_the_ball_will_move(table);
		Point vector_coordinates(direction.x - this->x, direction.y - this->y);
		Point final_vector_coordinates(koef * vector_coordinates.x, koef * vector_coordinates.y);

		Point final_point(final_vector_coordinates.x+this->x, final_vector_coordinates.y + this->y);

		cout<<final_point.x<<" "<<final_point.y<<endl; 
		// set x and y of ball to final point coordiantes;
	}
	*/
	void move(Table table)
	{
		////////Change koef
		double koef = 1 / this->strength;

		//// x1 = (1 - koef) * this->x + koef
		//// (xt(direction.x) - (1 - koef)*this->x)/ t = x1
		//// (yt(direction.y) - (1 - koef)*this->y)/ t = y2

		Point final_point(round((direction.x - (1 - koef)*this->x)/ koef) , round((direction.y - (1 - koef)*this->y)/ koef));
		////TO DO
		cout<<final_point.x<<" "<<final_point.y<<endl; 

		//// Check if ball hits the corner
		for(int i = 0; i < table.points.size(); i++)
		{
			if(table.points[i].x == final_point.x && table.points[i].y == final_point.y)
			{	
				this->x = this->start_x;
				this->y = this->start_y;
				return;
			}
		}
		

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
		double curr_num = atof(curr_num_as_string.c_str());

		string curr_num_as_string2;
		getline(S, curr_num_as_string2, ' ');
		double curr_num2 = atof(curr_num_as_string2.c_str());

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
	double diameter = atof(diameter_of_ball_as_string.c_str());

////coordinates of ball
	string line3;
	getline(istream, line3);

	stringstream S3(line3);

	string x_as_string;
	getline(S3, x_as_string, ',');
	double x_coordinate = atof(x_as_string.c_str());

	string y_as_string;
	getline(S3, y_as_string, ' ');
	double y_coordinate = atof(y_as_string.c_str());

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
	while (table.check_if_rectangle() != 1)
	{
		write_to_file();
		read_from_file(table, ball);
	}
	

	//Printing Ball
	cout<<ball.get_x()<<endl;
	cout<<ball.get_y()<<endl;
	cout<<ball.get_diameter()<<endl;

	//Printing table
	table.print_points();

	//input sila, direction.x direction.y    primer 1: 2     230      110   
	cout<<"Sila:"<<endl;
	float strenght;
	int direction_x, direction_y;
	cin>>strenght;
	cin>>direction_x;
	cin>>direction_y;
	cout<<strenght<<"|"<<direction_x<<"|"<<direction_y<<endl;

	ball.direction.x = direction_x;
	ball.direction.y = direction_y;
	ball.strength = strenght;

	//cout<<ball.find_length_of_vector_which_the_ball_will_move(table)<<endl;

	ball.move(table);

	return 0;
}