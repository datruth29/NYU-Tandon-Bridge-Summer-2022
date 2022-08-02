#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter a positive number: ";
    cin >> n;


    int max_rows = n;
    // Top half
    for (int row = 0; row < max_rows; row++)
    {
        int stars = (2 * n) - 1;

        for (int j = 0; j < row; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < stars; k++)
        {
            cout << "*";
        }

        n--;
        cout << endl;
    }

    // Bottom half
    n++;

    for (int row = max_rows-1; row >= 0; row--)
    {
        int stars = (2 * n) - 1;

        for (int j = 0; j < row; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < stars; k++)
        {
            cout << "*";
        }

        n++;
        cout << endl;
    }
    return 0;
}