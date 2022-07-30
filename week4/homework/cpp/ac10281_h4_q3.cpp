#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int userInput;
    int binaryPosition = 0;
    long long int binaryResult = 0;  

    cout << "Enter decimal number: " << endl;
    cin >> userInput;

    int originalInput = userInput;

    while (userInput > 0)
    {
        if (userInput % 2 == 1)
        {
            binaryResult += pow(10, binaryPosition);
        }

        binaryPosition++;
        userInput /= 2;
    }
    
    cout << "The binary representation of " << originalInput << " is " << binaryResult;
    return 0;
}