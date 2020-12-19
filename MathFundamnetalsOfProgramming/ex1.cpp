#include <iostream>
using namespace  std;
const int N = 50;

void print(int A[][N],int n, int m)
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
/*void sum_dynam(int **A,int **B,int n, int m)
{




}*/
int main()
{
	int A[5][N];
	
	int n1,n2;	
	cin >> n1 >> n2;
	cout<<"Opa"<<endl;
	for(int i = 0;i <n1;i++)
	{
		for(int j = 0; j < n2; j++)
		{
			cin >> A[i][j];
		}
	}
	cout<<"-------"<<endl;
	int B[5][N];
	for(int i = 0;i <n1;i++)
	{
		for(int j = 0; j < n2; j++)
		{
			cin >> B[i][j];
		}
	}

	int C[5][N];
	
	//sMult(B,n1,n2,-1);

	cout<<"First Matrix"<<endl;
	print(A,n1,n2);
	cout<<"Second Matrix"<<endl;
	print(B,n1,n2);

	cout<<"C after subtraction"<<endl;
	sub(A,B,C,n1,n2);
	print(C,n1,n2);

	






}
