#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Vector{
	int N;
	int *arr;
public:
	Vector(int N, int arr[])
	{
		this->arr = new int[N];
		for (int i = 0; i < N; ++i)
		{
			this->arr[i] = arr[i];
		}
	}
	int operator[](int index)
	{
		return this->arr[index];
	}
	int get_size()
	{
		return this->N;
	}
};
class Matrix{
	int N;
	int M;
	Vector *vectors;
	Matrix(int n, int m)
	{	
		this->N = n;
		this->M = m;
		//this->vectors = new Vector[M];
		this->vectors = (Vector *) malloc(m);
		for(int i = 0; i < m; i++){
			int *arr;
			Vector  currVector(n, arr);
			this->vectors[i] = currVector;
		}
	}
public:
	static Matrix from_array(int N, int M, int *arr) 
	{
		Matrix currMatrix(N, M);
		for (int i = 0; i < M; ++i)
		{
			Vector currVector = currMatrix[i];
			for (int j = 0; j < N; ++j)
			{
				//currMatrix.vectors[col][row] = arr[col][row];
				currVector = Vector(N, arr);
			}
		}
		return currMatrix;
	}
	Vector operator[](int index)
	{
		return vectors[index];
	}


	static Matrix from_matrix(Matrix other){
	
		Matrix currMat(other.get_N(), other.get_M());
		currMat.vectors = other.vectors;
		return currMat;
	}
	int get_N()
	{
		return this->N;
	}
	int get_M()
	{
		return this->M;
	}
	

	/*void operator+(int value)
	{
		for (int col = 0; col < M; ++col)
		{
			//Vector vector = vectors[col];
			for (int row = 0; row < N; ++row)
			{
				vectors[col][row] += value;
				//vector = Vector(N, arr);
			}
		}
	}
	*/


	
	





};
int main()
{
	return 0;
}