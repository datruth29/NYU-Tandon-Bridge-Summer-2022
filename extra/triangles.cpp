#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter a positive number: ";
    cin >> n;

    int max = (2 * n - 1);

    for (int i = 1; i <= max; i++)
    {
        int row = (n - i);

        // We need to get the absolute value for the row
        if (row < 0)
        {
            row = -1 * row;
        }

        int spaces = n - row - 1;
        int stars = (2 * row)+1;

        for (int k = 0; k < spaces; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}