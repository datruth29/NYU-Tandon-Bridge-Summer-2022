#include <iostream>
using namespace std;

const int ARR_SIZE = 6;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPossArrSizePtr);
void printArray(int arr[], int arrSize);

int main() {
    int arr[ARR_SIZE] = {3, -1, -3, 0, 6, 4};


    // First Function
    cout << "getPosNums1 Result:" << endl;
    cout << "-------------------" << endl;
    int size_one = 0;
    int* arr_one = getPosNums1(arr, ARR_SIZE, size_one);
    printArray(arr_one, size_one);

    cout << endl << endl;
    // Second Function
    cout << "getPosNums2 Result:" << endl;
    cout << "-------------------" << endl;
    int size_two = 0;
    int* arr_two = getPosNums2(arr, ARR_SIZE, &size_two);
    printArray(arr_two, *size_two);
    
    cout << endl << endl;
   // Third Function
    cout << "getPosNums3 Result:" << endl;
    cout << "-------------------" << endl;
    int size_three = 0;
    int* arr_three = nullptr;
    getPosNums3(arr, ARR_SIZE, arr_three, size_three);
    printArray(arr_three, size_three);

    cout << endl << endl;
   // Fourth Function
    cout << "getPosNums2 Result:" << endl;
    cout << "-------------------" << endl;
    int size_four = 0;
    int* arr_four = nullptr;
    getPosNums4(arr, ARR_SIZE, &arr_four, &size_four);
    printArray(arr_four , size_four);

    delete [] arr_one;
    delete [] arr_two;
    delete [] arr_three;
    delete [] arr_four;
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    int* new_arr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            new_arr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }
    return new_arr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    int* new_arr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            new_arr[*outPosArrSizePtr] = arr[i];
            *outPosArrSizePtr += 1;
        }
    }
    return new_arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    outPosArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    *outPosArrSizePtr = 0;
    *outPosArrPtr = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[*outPosArrSizePtr] = arr[i];
            *outPosArrSizePtr += 1;
        }
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "Position[" << i << "] => " << arr[i] << endl;
    }
}