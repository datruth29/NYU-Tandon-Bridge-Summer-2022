#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PIN_SIZE = 5;
const int MAX_DIGITS = 3;
const int CHALLENGE_SIZE = 10;
const int USER_PIN[5] = {1, 2, 3, 4, 5};

void randomizeChallengeArray(int arr[], int arrSize);
bool authenticationCheck(int userPin, int arr[]);

void randomizeChallengeArray(int arr[], int arrSize) {
    srand(time(0));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = (rand() % MAX_DIGITS) + 1;
    }
}

bool authenticationCheck(int userPin, int arr[]) {
    int digit;
    int pinPosition;
    bool authenticate;

    for (int i = PIN_SIZE-1; i >= 0; i--) {
        digit = userPin% 10;
        pinPosition = USER_PIN[i];

        authenticate = (digit == arr[pinPosition]);
        if (!authenticate)
            break;
        
        userPin /= 10;
    }

    return authenticate;
}

int main() {
    int challengeArray[CHALLENGE_SIZE];
    int userEntry;
    int digit;
    int pinPosition;

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
    cout << ">: ";
    cin >> userEntry;

    cout << endl;

    bool authenticate = authenticationCheck(userEntry, challengeArray);
    if (authenticate) {
        cout << "Your PIN is correct";
    } else {
        cout << "Your PIN is not correct";
    }
    return 0;
}