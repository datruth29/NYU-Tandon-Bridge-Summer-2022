#include <iostream>

using namespace std;

const int START_LETTER = 97;
int main()
{
    int userInput;
    
    cout << "Please enter a positive integer: ";
    cin >> userInput;

    for (int i = 0; i < userInput; i++)
    {
        for (int j = 1; j <= userInput + (i * 2); j++)
        {
            if (j == userInput + i || j == userInput - i)
            {
                cout << char(START_LETTER + i);
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

//     for (int i = userInput-2; i >= 0; i--)
//     {
//         for (int j = 1; j < userInput-i; j++)
//         {
//             cout << " ";
//         }
//         cout << char(START_LETTER + i);
//         for (int j = (i*2)-1; j > 0; j--)
//         {
//             cout << " ";
//         }
//         if (i != 0)
//         {
//             cout << char(START_LETTER + i);
//         }
//         cout << endl;
// 
//     }
    return 0;
}