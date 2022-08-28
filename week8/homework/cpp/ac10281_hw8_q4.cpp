#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PIN_SIZE = 5;
const int MAX_DIGITS = 3;
const int CHALLENGE_SIZE = 10;
const int USER_PIN[5] = {1, 2, 3, 4, 5};

void randomizeChallengeArray(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

void randomizeChallengeArray(int arr[], int arrSize) {
    srand(time(0));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % MAX_DIGITS) + 1;
    }
    
}

int main() {
    int challengeArray[CHALLENGE_SIZE];
    int userEntry;

    randomizeChallengeArray(challengeArray, CHALLENGE_SIZE);
    
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: \t";

    for (int i = 0; i < CHALLENGE_SIZE; i++) {
        cout << i << "\t";
    }

    cout << endl;
    cout << "NUM: \t";

    for (int i = 0; i < CHALLENGE_SIZE; i ++) {
        cout << challengeArray[i] << "\t";
    }

    cout << endl;
    return 0;
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ", ";
    }
    cout << "]";
}