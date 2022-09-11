#include <iostream>
#include <string>

using namespace std;
const int MAX_ALPHA = 26;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const int ALIGN_WITH_MOD = 7;
const int UPPERCASE_LOWER_BOUND = 65;
const int UPPERCASE_UPPER_BOUND = 90;
const int LOWERCASE_LOWER_BOUND = 97;
const int LOWERCASE_UPPER_BOUND = 122;
const int UPPER_TO_LOWERCASE = 32;

bool isAlpha(char character);
bool isAnagram(string sentence_a, string sentence_b);
int* countCharacters(string sentence);
void processCharacter(int count_arr[], char character);

int main() {
    string first_userInput;
    string second_userInput;
    int wordCount = 0;
    int anagramCheck[MAX_ALPHA] = { 0 };

    cout << "Please the first sentence: " << endl;
    getline(cin, first_userInput);
    cout << "Please the second sentence: " << endl;
    getline(cin, second_userInput);

    if (isAnagram(first_userInput, second_userInput)) {
        cout << "The two sentences are an anagram!" << endl;
    } else {
        cout << "The two sentences are NOT an anagram! :( Sorry!" << endl;
    }
    
    return 0;
}

bool isAlpha(char character) {
    return ((character >= UPPERCASE_LOWER_BOUND && character <= UPPERCASE_UPPER_BOUND) ||
            (character >= LOWERCASE_LOWER_BOUND && character <= LOWERCASE_UPPER_BOUND));
}

bool isAnagram(string sentence_a, string sentence_b) {
    int* count_a = countCharacters(sentence_a);
    int* count_b = countCharacters(sentence_b); 
    bool result;

    for (int i = 0; i < MAX_ALPHA; i++) {
        result = (count_a[i] == count_b[i]);
        if (!result) {
            break;
        }
    }

    return result;
}

int* countCharacters(string sentence) {
    int* counter = new int[MAX_ALPHA]();
    for(char c : sentence) {
        if (isAlpha(c)) {
            processCharacter(counter, c);
        }
    }

    return counter;
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
