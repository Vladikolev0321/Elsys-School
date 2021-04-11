#include <iostream>
using namespace std;
const int N = 50;

/*
Да се напише програма, която по 
подадена асоциирана матрица превръща графа в списък на ребрата.
*/

void print(int A[2*N*N][2], int n, int m) {
    for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void transformToEdgeList(int matrix[][N], int edgeList[2*N*N][2]) {

    int counter = 0;
    for (int i = 0; i < N; i++) { // Редовете на матрицата (върховете)
        for (int j = 0; j < N; j++) { // Колоните на матрицата (ребрата)
            if (matrix[i][j]) { // Проверка дали имаме единица
                 edgeList[counter][0] = i + 1; // Увеличаваме заради индекса
                 edgeList[counter][1] = j + 1;
                 counter++;
            }
        }
    }
}

int main() {
    
    int matrix[][N] =  {    {0, 0, 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0},
                            {1, 0, 0, 0} 
                       };

    int edgeList[2*N*N][2]; // [[2,3], [4,1], .....]

    transformToEdgeList(matrix, edgeList); 
    print(edgeList, 2, 2);
    

    return 0;
}