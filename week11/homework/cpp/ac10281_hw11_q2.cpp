#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
int isSorted(int arr[], int arrSize);
int squared(int num);
void printArray(int arr[], int arrSize);

int main() {
    int arr[6] = {0, 3, 3, 4, 5, 16};
    cout << sumOfSquares(arr, 6) << endl;
    cout << isSorted(arr, 6) << endl;
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize <= 0) {
        return 0;
    }

    if (arrSize == 1) {
        return squared(arr[0]);
    }

    //cout << squared(arr[arrSize-1]) << endl;

    return squared(arr[arrSize-1]) + sumOfSquares(arr, arrSize-1);
}

int isSorted(int arr[], int arrSize) {
    if (arrSize <= 0) {
        return false;
    }

    if (arrSize == 1) {
        return true;
    } 

    bool result = (arr[arrSize-1] >= arr[arrSize-2]);

    if (result) {
        return isSorted(arr, arrSize - 1);
    }

    return false;
    
}

int squared(int num) {
    return num * num;
}