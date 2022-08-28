#include <iostream>
#include <string>
using namespace std;

bool isCharDigit(char ch);
void replaceWithX(string &str, int startPos, int length);

bool isCharDigit(char ch) {
    return (int(ch) >= 48 && int(ch) <= 57);
}

void replaceWithX(string &str, int startPos, int length) {
    for (int i = startPos; i < startPos + length; i++) {
        str[i] = 'x';
    }
}

int main() {
    string userInput;
    bool numCheck = false;
    char prevCharacter = ' ';
    char currCharacter;
    int startPosition = 0;
    int length = 0;

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    for (int i = 0; i < userInput.length(); i++) {
        currCharacter = userInput[i];

        if (currCharacter == ' ' && numCheck) {
            replaceWithX(userInput, startPosition, length);
            startPosition = 0;
            length = 0;
        }

        if (isCharDigit(currCharacter) && prevCharacter == ' ') {
            numCheck = true;
            startPosition = i;
            length++;
        }

        if (isCharDigit(currCharacter) && isCharDigit(prevCharacter) && numCheck) {
            length++;
        }

        if (!isCharDigit(currCharacter) && numCheck) {
            numCheck = false;
            startPosition = 0;
            length = 0;
        }
        prevCharacter = currCharacter;
    }

    if (numCheck) {
        replaceWithX(userInput, startPosition, length);
    }

    cout << userInput;

    return 0;
}