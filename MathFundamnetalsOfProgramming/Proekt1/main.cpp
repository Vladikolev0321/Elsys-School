#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

const int M = 4;

void print_matrix(double A[][M],int n, int m)
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
void Gaus(double A[][5], double X[], int n)
{

	for(int i = 0;i < 4;i++)
	{
		for(int k = i+1;k < 4;k++)
		{
			double num = -(A[k][i]/A[i][i]);
			for(int j = i;j <= 4;j++)
			{
				A[k][j] += A[i][j]*num;
			}
		}
	}

	for(int i = 4-1;i>=0;--i)
	{
		X[i] = A[i][4]/A[i][i];
		for(int j = 4-1;i < j;--j)
		{
			X[i] -= (X[j] * A[i][j]) / A[i][i];
		}
	}

	cout<<endl;
	for (int y = 0; y < n; y++) {
		cout << X[y] << " ";
	}
	cout<<endl;
	//X[n] = {0};

	/*for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(A[j][i] > A[i][i])
			{
				for(int k = 0; k < n+1; k++)
				{
					double temp = A[i][k];
					A[i][k] = A[j][k];
					A[j][k] = temp;
				}
			}
		}
	}

	//print_matrix(A, n, n+1);

	for(int i = 0; i < n;i++)
	{
		for(int j = i+1; j < n; j++)
		{
			double del = -(A[j][i]/A[i][i]);
			for(int k = i; k <= n; k++)
			{
				A[j][k] += del * A[i][k];
			}
		}
	}

	for(int i = n-1; i >= 0;i--)
	{
		X[i] = A[i][n] / A[i][i];
		for (int j = n-1; i<j; --j)
		{
			X[i] -= (X[j] * A[i][j]) / A[i][i];
		}
	}
	//print_matrix(A, n, n+1);
	cout<<endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout<<A[i][j]<<" ";

		}
		cout << endl;
	}
	cout<<endl;
	for (int y = 0; y < n; y++) {
		cout << X[y] << " ";
	}
	*/
	
}
void sum(const int A[][M], const int B[][M], int C[][M],int n, int m)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}
void read_matrix_from_file(double A[][M],int n, int m)
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
void get_our_bills(double Input[][M],double ResBills[][M], int n, int m)
{
	double values[4] = {0.129, 1.461, 85.07, 0.132};

	for (int i = 0; i < m; i++)
	{	
		double sum = 0;
		for (int j = 0; j < n - 1; j++)
		{	
		    sum += Input[i][j] * values[j]; 
		}
		ResBills[0][i] = Input[4][i] - sum;
	}

	cout<<endl;
	print_matrix(ResBills, n, m);
}
void find_diff_in_quantity(double Input[][M], double Res[][4])
{
	double values[4] = {0.129, 1.461, 85.07, 0.132};
	//print_matrix(Input, 5, 4);
	double Input2[4][5];
	for (int x = 0 ; x < 4; x++)
	{	
  		for (int y = 0 ; y < 5; y++)
  		{
  			if(y == 4)
  			{
  				Input2[x][4] = Input[4][x];
  			}
  			else
  			{
    			Input2[x][y] = Input[x][y];
  			}
  		}
	}
	double X[4]; 
	Gaus(Input2, X, 4);

	for (int i = 1; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			Res[i+1][j] = Res[i+1][j]*(1 - values[i-1]/X[i-1]);
		}
	}

	print_matrix(Res, 5, 4);


	/*
	cout<<endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout<<Input2[i][j]<<" ";
		}
		cout << endl;
	}
	*/




	
	


}
int main()
{
	double Input[5][4];
	
	int n1,n2;
	n1 = 5;
	n2 = 4;

	read_matrix_from_file(Input, n1, n2);

	print_matrix(Input, n1, n2);

	double ResBills[5][4];

	get_our_bills(Input, ResBills, n1, n2);

	double Res[4][5];

	find_diff_in_quantity(Input, ResBills);


}
