#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

bool isPalindrome(string str) {

    bool result = true;

    for (int i = 0; i < (str.length()-1)/2; i++) {
        if (str[i] != str[str.length()-1-i] ){
            result = false;
            break;
        }
    }

    return result;
}

int main() {
    string word;
    string result = "is not a palindrome";

    cout << "Please enter a word: ";
    cin >> word;

    if (isPalindrome(word))
        result = "is a palindrome";

    cout << word << " " << result;
}