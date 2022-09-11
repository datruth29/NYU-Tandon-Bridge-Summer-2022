#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arrOne[6] = {1, 1, 2, 2, 3, 3};
    int arrOneSize;
    int* arrOneResult = findMissing(arrOne, 6, arrOneSize);
    int arrTwo[6] = {3, 1, 3, 0, 6, 4};
    int arrTwoSize;
    int* arrTwoResult = findMissing(arrTwo, 6, arrTwoSize);

    printArray(arrOneResult, arrOneSize);
    printArray(arrTwoResult, arrTwoSize);

    
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    bool* temp = new bool[n]{false};
    resArrSize = n;

    for (int i = 0; i < n; i++) {
        int pos = arr[i];
        if (!temp[pos]) {
            temp[pos] = true;
            resArrSize--;
        }
    }

    int* result = new int[resArrSize]{};
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!temp[i]) {
            result[count] = i;
            count++;
        }
    }

    delete [] temp;

    return result;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "Position[" << i << "] => " << arr[i] << endl;
    }
}