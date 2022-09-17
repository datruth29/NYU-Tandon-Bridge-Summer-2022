#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
bool endsWithPunctuation(string word);
const char SPACE = ' ';
const char PERIOD = '.';
const char COMMA = ',';
const char EXCLAMATION = '!';
const char QUESTION = '?';
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
    string word = "";
    int start = 0;
    size_t space_location = sentence.find(SPACE);
    outWordsArrSize = 0;

    while (space_location != string::npos) {
        word = sentence.substr(start, space_location - start);
        if (endsWithPunctuation(word)) {
            word.pop_back();
        }
        words[outWordsArrSize] = word;
        start = space_location + 1;
        space_location = sentence.find(SPACE, start);
        outWordsArrSize++;
    }

    word = sentence.substr(start, space_location - start);
    if (endsWithPunctuation(word)) {
        word.pop_back();
    }
    words[outWordsArrSize] = word;
    outWordsArrSize++;

    return words;
}

void printArray(string* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "[" << i << "] => " << arr[i] << endl;
    }
}

bool endsWithPunctuation(string word) {
    char lastChar = word.back();
    return (lastChar == PERIOD || 
            lastChar == COMMA || 
            lastChar == EXCLAMATION || 
            lastChar == QUESTION);
}