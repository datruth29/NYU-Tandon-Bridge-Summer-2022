#include <iostream>
#include <string>

using namespace std;

const char ROMAN_SYMBOL_M = 'M';
const char ROMAN_SYMBOL_D = 'D';
const char ROMAN_SYMBOL_C = 'C';
const char ROMAN_SYMBOL_L = 'L';
const char ROMAN_SYMBOL_X = 'X';
const char ROMAN_SYMBOL_V = 'V';
const char ROMAN_SYMBOL_I = 'I';

const int ROMAN_VALUE_M = 1000;
const int ROMAN_VALUE_D = 500;
const int ROMAN_VALUE_C = 100;
const int ROMAN_VALUE_L = 50;
const int ROMAN_VALUE_X = 10;
const int ROMAN_VALUE_V = 5;
const int ROMAN_VALUE_I = 1;

int main()
{
    int userInput;
    string romanValue = "";

    cout << "Please enter a number: ";
    cin >> userInput;

    int originalInput = userInput;
    
    while (userInput > 0)
    {
        if (userInput >= 1000)
        {
            romanValue += ROMAN_SYMBOL_M;
            userInput -= ROMAN_VALUE_M;
        }
        else if (userInput >= 500)
        {
            romanValue += ROMAN_SYMBOL_D;
            userInput -= ROMAN_VALUE_D;
        }
        else if (userInput >= 100)
        {
            romanValue += ROMAN_SYMBOL_C;
            userInput -= ROMAN_VALUE_C;
        }
        else if (userInput >= 50)
        {
            romanValue += ROMAN_SYMBOL_L;
            userInput -= ROMAN_VALUE_L;
        }
        else if (userInput >= 10)
        {
            romanValue += ROMAN_SYMBOL_X;
            userInput -= ROMAN_VALUE_X;
        }
        else if (userInput >= 5)
        {
            romanValue += ROMAN_SYMBOL_V;
            userInput -= ROMAN_VALUE_V;
        }
        else
        {
            romanValue += ROMAN_SYMBOL_I;
            userInput -= ROMAN_VALUE_I;
        }
    }

    cout << originalInput << " is " << romanValue;

    return 0;
}