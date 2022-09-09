#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    string userInput;

    cout << "Enter a sentence:" << endl;
    getline(cin, userInput);

    cout << userInput;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string* words = new string[sentence.length()];
    return words;
}