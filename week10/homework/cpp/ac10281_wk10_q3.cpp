#include <iostream>
#include <vector>
using namespace std;

void main1();
void resizeArray(int*& arr, int currentSize, int newSize);
void main2();
void printArray(int arr[], int arrSize);

int main() {
    main1();
    main2();
    return 0;
}

void main1() {
    int arrSize = 8;
    int* arr = new int[arrSize];
    int userInput = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;

    int index = 0;
    while (userInput != -1) {
        cin >> userInput;
        if (index >= arrSize) {
            resizeArray(arr, arrSize, arrSize * 2);
            arrSize *= 2;
        }
        arr[index] = userInput;
        index++;
    }

    int searchNumber;
    cout << "Please enter a number you want to search:" << endl;
    cin >> searchNumber;

    int* arrLocations = new int[arrSize];
    int arrLocationsIndex = 0;

    for(int i = 0; i < arrSize; i++) {
        if (arr[i] == searchNumber) {
            arrLocations[arrLocationsIndex] = i+1;
            arrLocationsIndex++;
        } else if (arr[1] == -1) {
            break;
        }
    }

    if (arrLocationsIndex == 0) {
        cout << searchNumber << " is not in any lines.";
    } else {
        cout << searchNumber << " is in lines " << arrLocations[0];
        for (int i = 1; i < arrLocationsIndex; i++) {
            cout << ", " << arrLocations[i];
        }
        cout << "." << endl;
    }
}

void resizeArray(int*& arr, int currentSize, int newSize) {
    int* temp = new int[newSize];

    for (int i = 0; i  < currentSize; i++) {
        temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
}

void main2() {
    vector<int> arr;
    int userInput = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;

    while (userInput != -1) {
        cin >> userInput;
        arr.push_back(userInput);

    }

    int searchNumber;
    cout << "Please enter a number you want to search:" << endl;
    cin >> searchNumber;

    int arrLocationsIndex = 0;
    vector<int> arrLocations;

    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] == searchNumber) {
            //cout << "I'm here" << endl;
            arrLocations.push_back(i + 1);
        }
    }

    if (arrLocations.empty()) {
        cout << searchNumber << " is not in any lines.";
    } else {
        cout << searchNumber << " is in lines " << arrLocations[0];
        for (int i = 1; i < arrLocations.size(); i++) {
            cout << ", " << arrLocations[i];
        }
        cout << "." << endl;
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "Position[" << i << "] => " << arr[i] << endl;
    }
}