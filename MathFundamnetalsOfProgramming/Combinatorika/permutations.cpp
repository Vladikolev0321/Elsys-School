#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


// 1 2 3 4 5
// startIndex = 0;
void printPermutations(int arr[], int n, int startIndex) {
    if(n == startIndex + 1){
        print(arr, n);
        return;
    }

    for(int i = startIndex; i < n; ++i){
        swap(arr[i], arr[startIndex]);
        printPermutations(arr, n, startIndex + 1);
        swap(arr[i], arr[startIndex]);
    }
}


int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    
    printPermutations(arr, n, 0);
}