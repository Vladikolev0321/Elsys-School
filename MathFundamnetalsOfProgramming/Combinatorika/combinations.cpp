#include <iostream>
using namespace std;

/*
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
*/
// functional programming way -> recurcsive
void printArr(int *arr, int n){
    int a = 5;
    if(n == 0){ return;}
    cout<< arr[0] << " ";
    printArr(arr+1, n-1);


}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
/*
bool sorted(int *arr, int size){
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }    
    }
    return true;
}
*/

// recursive way
bool sorted(int *arr, int size){
    
    if(size<=1) return true;

    if(arr[0] < arr[1]) return false;
    return sorted(arr+1, size-1);
}


// 1 2 3 4 5
// startIndex = 0;
void printCombination(int arr[], int n, int startIndex) {
    if(n == startIndex + 1){
        if(sorted(arr, n)){
            printArr(arr, n);
        }
        return;
    }

    for(int i = startIndex; i < n; ++i){
        swap(arr[i], arr[startIndex]);
        printCombination(arr, n, startIndex + 1);
        swap(arr[i], arr[startIndex]);
    }
}


int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    
    printCombination(arr, n, 0);
}