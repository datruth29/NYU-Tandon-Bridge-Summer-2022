#include <iostream>
#include <string>

using namespace std;
const int MAX_ALPHA = 26;
const int ALIGN_WITH_MOD = 7;
const int UPPERCASE_LOWER_BOUND = 65;
const int UPPERCASE_UPPER_BOUND = 90;
const int LOWERCASE_LOWER_BOUND = 97;
const int LOWERCASE_UPPER_BOUND = 122;
const int UPPER_TO_LOWERCASE = 32;

const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
bool isAlpha(char character);
void printCounts (int count_arr[], int wordCount);
void processCharacter(int count_arr[], char character);
void printArray(int arr[], int size);

int main() {
    string userInput;
    int wordCount = 0;
    int letterCount[MAX_ALPHA] = { 0 };

    cout << "Please enter a sentence. Don't include digits: " << endl;
    getline(cin, userInput);

    bool notInWord = true;
    char currentChar;

    for (int i = 0; i < userInput.length(); i++) {
        currentChar = userInput.at(i);

        if (isAlpha(currentChar)) {
            if (notInWord) {
                wordCount++;
                notInWord = false;
            }
            processCharacter(letterCount, currentChar);
        } else {
            notInWord = true;
        }
    }

    printCounts(letterCount, wordCount);
    return 0;
}

bool isAlpha(char character) {
    return ((character >= UPPERCASE_LOWER_BOUND && character <= UPPERCASE_UPPER_BOUND) ||
            (character >= LOWERCASE_LOWER_BOUND && character <= LOWERCASE_UPPER_BOUND));
}

void processCharacter(int count_arr[], char character) {
    int position = static_cast<int>(character);

    if (position >= UPPERCASE_LOWER_BOUND && position <= UPPERCASE_UPPER_BOUND) {
       position = static_cast<int>(character) + UPPER_TO_LOWERCASE;
    }
    position += ALIGN_WITH_MOD;
    cout << "Character => " << character << ", pos =>" << position << ", after % " << position % MAX_ALPHA << endl;
    count_arr[position % MAX_ALPHA]++;
}

void printCounts (int count_arr[], int wordCount) {
    cout << wordCount << '\t' << "words" << endl;

    for (int i = 0; i < MAX_ALPHA; i++) {
        if (count_arr[i] > 0) {
            cout << count_arr[i] << '\t' << ALPHA[i] << endl;
        }
    }
}