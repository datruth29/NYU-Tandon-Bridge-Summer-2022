#include <iostream>

using namespace std;

int main()
{
    int inputString;

    cin >> inputString;

    while (inputString > 0)
    {
        binString = to_string(inputString%2) + binString;
        inputString = inputString/2;
    }

    cout << binString << endl;
    return 0;
}