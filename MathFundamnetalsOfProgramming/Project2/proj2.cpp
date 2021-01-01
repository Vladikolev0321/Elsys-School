#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
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
	list<Point> points;
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
};

void read_from_file(Table &table)
{
	string file_name = "proj2.txt";

	ifstream istream;
	istream.open(file_name);

	
	string line1;
	getline(istream, line1);

	stringstream S(line1);

	for (int i = 0; i < 4; ++i)
	{
		string curr_num_as_string;
		getline(S, curr_num_as_string, ',');
		int curr_num = stoi(curr_num_as_string.c_str());

		string curr_num_as_string2;
		getline(S, curr_num_as_string2, ' ');
		int curr_num2 = stoi(curr_num_as_string2.c_str());

		//cout << curr_num << ',' << curr_num2 <<endl;

		Point curr_point(curr_num, curr_num2);
		table.add_point(curr_point);

	}
///diameter
	string line2;
	getline(istream, line2);

	stringstream S(line2);
	string diameter_of_ball_as_string;
	getline(S, diameter_of_ball_as_string, ' ');
	int diameter = stoi(diameter_of_ball_as_string.c_str());

////coordinates of ball
	string line3;
	getline(istream, line3);

	stringstream S(line3);

	string x_as_string;
	getline(S, x_as_string, ',');
	int x_coordinate = stoi(x_as_string.c_str());

	string y_as_string;
	getline(S, y_as_string, ' ');
	int y_coordinate = stoi(y_as_string.c_str());
	

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
	read_from_file(table);

	table.print_points();


	return 0;
}