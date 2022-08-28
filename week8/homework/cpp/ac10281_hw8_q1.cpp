#include <iostream>
using namespace std;

const int ARRAY_SIZE = 20;

int minInArray(int arr[], int arrSize);
void printLocations(int arr[], int arrSize, int num);

int minInArray(int arr[], int arrSize){

    int min = arr[0];

    for (int i = 1; i < arrSize; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void printArr(int arr[], int arrSize){

    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){

    int arr[ARRAY_SIZE];

    cout << "Please enter 20 digits: " << endl;

    for (int i = 0; i < ARRAY_SIZE; i++){
        cin >> arr[i];
    }

    int min = minInArray(arr, ARRAY_SIZE);

    cout    << "The minimum value is " << min << ", and is located in the following indices: ";
    printLocations(arr, ARRAY_SIZE, min);

    return 0;
}