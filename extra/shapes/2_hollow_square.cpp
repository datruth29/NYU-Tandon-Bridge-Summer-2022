#include <iostream>

using namespace std;

int main()
{
    int userInput;
    cout << "Please enter a positive integer: ";
    cin >> userInput;

    for (int row = 0; row < userInput; row++)
    {
        for (int col = 0; col < userInput; col++)
        {
            if (row == 0 || row == userInput - 1)
            {
                cout << "*";
            }
            else if (col == 0 || col == userInput - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}