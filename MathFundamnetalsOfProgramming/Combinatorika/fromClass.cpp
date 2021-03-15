#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
void printArr(int* arr, int size) {
    for(int i = 0; i< size; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}
*/

void printArr(int* arr, int size) {
    if(!size) return;
    
    cout<< arr[0]<< " ";
    printArr(arr+1, size-1);
}

bool sorted(int* arr, int size) {
    if(size<=1) return true;

    if(arr[0] < arr[1]) return false;
    
    return sorted( arr +1, size-1);
}

void printPermutations(int* arr, int startIndex, int size) {
    if(startIndex == size-1) {
        if(sorted(arr, size)) {
            printArr(arr, size);
        }
        return;
    }

    for(int i = startIndex; i< size; ++i) {
        swap(arr[startIndex], arr[i]);
        printPermutations(arr, startIndex+1, size);
        swap(arr[startIndex], arr[i]);
    }
}

void print(int* arr, int n) {
    for(int i = 0; i< n; ++i) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

void printCombinations(int* arr, int n, int* combination, int k, int currK) {
    if(n < k - currK) {
        return;
    }

    if(currK == k) {
        print(combination, k);
        return;
    }

    combination[currK] = arr[0];
    printCombinations(arr+1, n-1, combination, k, currK+1);

    printCombinations(arr+1, n-1, combination, k, currK);
}


void printSingleCombination(std::vector<int> combination) {

    /* This function will print every possible
    different combination of the array elements. */

    for (unsigned int i = 0; i < combination.size(); i++) {
        if (i != combination.size() - 1) { std::cout << combination[i] << " "; }
        else { std::cout << combination[i] << std::endl; }
    }
}

void printCombinations(int arr[], int n, int k, int start, std::vector<int> combination) {

    /* The function for the combinations will be recursive too.
    Analogically to the function for the permutations, we will
    have a "start" variable again.

    There is a little difference, which we can use here - a
    vector for storing every combination. When we have found
    one of all possible combinations, we will print the values
    of this vector.

    Every time we will increment our start variable to make a
    shift from left to right and after this we will make it from
    right to left by deleting the last element from the last
    printed combination. We know that this algorithm won't print
    the combinations, which may repeat, because the recursion
    won't "have in mind" the last fixed element, which has been
    on first position. This way we get just the combinations,
    which are unique. */

    if (k == 0) {
        printSingleCombination(combination);
        return;
    }


    for (int i = start; i <= n - k; i++) {
        combination.push_back(arr[i]);
        printCombinations(arr, n, k - 1, i + 1, combination);
        combination.pop_back();
    }
}

void printCombinations(int* arr, int n, int k) {
    int* combination = new int[k];
    printCombinations(arr, n, combination, k, 0);
    delete[] combination;
}

int main() {
    int arr[] = {1,2,3,4,5};
    printCombinations(arr, 5, 3);

    return 0;
}

