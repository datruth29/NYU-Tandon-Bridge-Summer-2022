#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr[6] = {5, -2, 11, -7, 6, 4};

    oddsKeepEvensFlip(arr, 6);
    printArray(arr, 6);
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* holderArr = new int[arrSize];
    int index = 0, oddTracker = 0, evenTracker = arrSize-1;

    while (index < arrSize) {
        if (arr[index] % 2 == 0) {
            holderArr[evenTracker] = arr[index];
            evenTracker--;
        } else {
            holderArr[oddTracker] = arr[index];
            oddTracker++;
        }
        index++;
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = holderArr[i];
    }

    delete [] holderArr;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "Position[" << i << "] => " << arr[i] << endl;
    }
}