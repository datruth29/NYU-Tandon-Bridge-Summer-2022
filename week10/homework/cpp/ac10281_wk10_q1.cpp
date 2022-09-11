#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
const char SPACE = ' ';
void printArray(string* arr, int arrSize);

int main() {
    string userInput;

    cout << "Enter a sentence:" << endl;
    getline(cin, userInput);

    int result_size = 0;
    string* result = createWordsArray(userInput, result_size);

    printArray(result, result_size);

    delete [] result;
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string* words = new string[sentence.length()];
    int start = 0;
    int space_location = sentence.find(SPACE);
    outWordsArrSize = 0;

    while (space_location != string::npos) {
        words[outWordsArrSize] = sentence.substr(start, space_location - start);
        start = space_location + 1;
        space_location = sentence.find(SPACE, start);
        outWordsArrSize++;
    }

    words[outWordsArrSize] = sentence.substr(start);
    outWordsArrSize++;

    return words;
}

void printArray(string* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "[" << i << "] => " << arr[i] << endl;
    }
}