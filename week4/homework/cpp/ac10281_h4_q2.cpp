#include <iostream>
#include <string>

using namespace std;

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
            romanValue += "M";
            userInput -= 1000;
        }
        else if (userInput >= 500)
        {
            romanValue +="D";
            userInput -= 500;
        }
        else if (userInput >= 100)
        {
            romanValue += "C";
            userInput -= 100;
        }
        else if (userInput >= 50)
        {
            romanValue += "L";
            userInput -= 50;
        }
        else if (userInput >= 10)
        {
            romanValue += "X";
            userInput -= 10;
        }
        else if (userInput >= 5)
        {
            romanValue += "V";
            userInput -= 5;
        }
        else
        {
            romanValue += "I";
            userInput -= 1;
        }
    }

    cout << originalInput << " is " << romanValue;

    return 0;
}