#include <iostream>
#include <string>

using namespace std;

int main()
{
    int userInput;
    char binaryPosition;
    string binaryResult = "";

    cout << "Enter decimal number: " << endl;
    cin >> userInput;

    int originalInput = userInput;

    while (userInput > 0)
    {
        if (userInput % 2 == 1)
        {
            binaryPosition = '1';
        }
        else
        {
            binaryPosition = '0';
        }
        binaryResult = binaryPosition + binaryResult;
        userInput /= 2;
    }
    
    cout << "The binary representation of " << originalInput << " is " << binaryResult;
    return 0;
}