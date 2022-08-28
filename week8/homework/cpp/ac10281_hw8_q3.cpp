#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

void reverseArray(int arr[], int arrSize){
    int temp;
    for (int i = 0; i < (arrSize - 1) / 2; i++) {
        temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
}

void removeOdd(int arr[], int& arrSize){
    int evenCounter = 0;
    int decrement = 0;
    int temp;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            decrement++;
        }
        if (arr[i] % 2 == 0) {
            if (i > evenCounter) {
                temp = arr[i];
                arr[i] = arr[evenCounter];
                arr[evenCounter] = temp;
            }
                evenCounter++;
        }
    }
    arrSize -= decrement;
}

void splitParity(int arr[], int arrSize){
    int oddCounter = 0;
    int temp;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            if (i > oddCounter) {
                temp = arr[i];
                arr[i] = arr[oddCounter];
                arr[oddCounter] = temp;
            }
                oddCounter++;
        }
    }
}

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
}

void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}