#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;

    cout << "Enter a positive number: ";
    cin >> n;

    int max = 2 * n;

    // Top half
    for (int i = 0; i < n; i++)
    {
        int spaces = i;
        int stars = (2 * n) - (i * 2) - 1;

        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < stars; k++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Bottom half
    for (int i = n-1; i >= 0; i--)
    {
        int spaces = i;
        int stars = (2 * n) - (i * 2) - 1;


        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < stars; k++)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}