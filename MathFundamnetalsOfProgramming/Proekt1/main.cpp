#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

const int M = 4;

void print(double A[][M],int n, int m)
{

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<A[i][j]<<" ";

		}
		cout << endl;

	}
}
void read_matrix(double A[][M],int n, int m)
{
	string file_name;
	cin>>file_name;

	ifstream istream;
	istream.open(file_name);

	for(int i = 0; i < n; i++)
	{
		string line;
		getline(istream, line);
		
		stringstream S(line);

		for(int j = 0; j < m; j++)
		{
			string curr_num_as_string;
			getline(S, curr_num_as_string, ' ');
			//double curr_num = stod(curr_num_as_string);
			double curr_num = atof(curr_num_as_string.c_str());

			A[i][j] = curr_num;
		}	
	}
	istream.close();
	
}
int main()
{
	/*string file_name;
	cin>>file_name;

	ifstream istream;
	istream.open(file_name);
	*/

	double Input[5][4];
	
	int n1,n2;
	n1 = 5;
	n2 = 4;

	///read from file
	/*string file_name;
	cin>>file_name;

	ifstream istream;
	istream.open(file_name);

	for(int i = 0; i < n1; i++)
	{
		string line;
		getline(istream, line);
		
		stringstream S(line);

		for(int j = 0; j < n2; j++)
		{
			string curr_num_as_string;
			getline(S, curr_num_as_string, ' ');
			//double curr_num = stod(curr_num_as_string);
			double curr_num = atof(curr_num_as_string.c_str());

			Input[i][j] = curr_num;
		}	
	}
	
	istream.close();
//*/


	read_matrix(Input, 5, 4);
	

	print(Input, n1, n2);
}