#include <iostream>
#include <string>

using namespace std;
const int MAX_ALPHA = 26;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
bool isAlpha(char character);
void printCounts (int count_arr[], int wordCount);
void processCharacter(int count_arr[], char character);
void printArray(int arr[], int size);

int main() {
    string userInput;
    int wordCount = 0;
    int letterCount[MAX_ALPHA] = { 0 };

    cout << "Please enter a sentence. Don't include letters: " << endl;
    getline(cin, userInput);

    bool notInWord = true;
    char currentChar;

    for (int i = 0; i < userInput.length(); i++) {
        currentChar = userInput.at(i);

        if (!isAlpha(currentChar)) {
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
    // printArray(letterCount, MAX_ALPHA);


    
    return 0;
}

bool isAlpha(char character) {
    return (character == ' ' || character == ',' || character == '.');
}


void processCharacter(int count_arr[], char character) {
    int position = static_cast<int>(character);

    if (position >= 65 && position <= 90) {
       position = static_cast<int>(character) + 32;
    }
    position += 7 ;
    //cout << "Character => " << character << ", pos =>" << position << ", after % " << position % MAX_ALPHA << endl;
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

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << ALPHA[i] << " => ";
        cout << arr[i] << endl;
    }
}