#include<iostream>

using namespace std;

int main()
{
    char inLetter;

    cout << "Please enter a lower-case letter:" << endl;
    cin >> inLetter;

    int rows = inLetter - 'a';
    int letter = int(inLetter);

    cout << int('a') << endl;

    for (int i = 0; i <= rows; i++) 
    {
        int temp = i;
        if ((i > 0) && (i % 2) == 1)
        {
            temp = i - 32;
        }

        for (int z = 0; z < rows-i; z++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i*2; j++)
        {
            cout << char(int('a') + temp);
        }
        cout << endl;
    }

    return 0;
}