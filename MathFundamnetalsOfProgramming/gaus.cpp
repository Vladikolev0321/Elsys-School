#include <iostream>
using namespace std;
const int N = 50;
void print(double A[][N],int n, int m)
{

	for(int i = 0;i<n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<A[i][j]<<" ";

		}
		cout << endl;

	}


}

bool equal(int A[][N],int n1, int m1,const int B[][N],int n)
{
	for(int i = 0;i<n1;i++)
	{
		for(int j = 0; j < m1; j++)
		{
			if(A[i][j] != B[i][j])
			{
				return false;
			}

		}
	}

	return true;

}
void sum(const int A[][N], const int B[][N], int C[][N],int n, int m)
{

	for(int i = 0;i<n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}


}
void Transpose(const int A[][N], int T[][N], int n, int m)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0; j < m; j++)
		{
			T[j][i] = A[i][j];		
		}
	}



}
void sMult(int A[][N],int m , int n, int s)
{
	for(int i = 0;i < m;i++)
	{
		for(int j = 0; j < n; j++)
		{
			A[i][j] = A[i][j]*s;		
		}
	}
	
	

}
void sub(const int A[][N],  int B[][N],int C[][N],int n, int m)
{
	sMult(B,n,m,-1);
	sum(A,B,C,n,m);
		

}
void Gaus(double A[][N],int n)
{
	double X[n] = {0};

	for(int i = 0; i < n;i++)
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
	print(A,n,n+1);

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
	print(A,n,n+1);
	cout<<endl;
	for (int y = 0; y < n; y++) {
		cout << X[y] << " ";
	}
}
int main()
{
	int n;
	cout<<"Enter N:"<<endl;
	cin>>n;
	double A[n][N];
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			cin>>A[i][j];
		}
	}

	Gaus(A,n);
	
	
	



}
