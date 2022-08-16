#include <iostream>

using namespace std;

int main()
{
    int userInput;
    int spaces;
    cout << "Please enter a positive integer: ";
    cin >> userInput;


    int maxLine = userInput * 2;
    int maxNums;
    int maxSpaces;

    for (int row = 0; row < maxLine - 1; row++)
    {
        if (row + 1 <= maxLine / 2)
        {
            maxNums = row + 1;
        }
        else
        {
            maxNums = maxLine - row - 1;
        }

        maxSpaces = (maxLine - 1) - (2 * maxNums) ;

        for (int num = 1; num <= maxNums; num++)
        {
           cout << num; 
        }
        
        for (int spaces = 0; spaces < maxSpaces; spaces++)
        {
            cout << " ";
        }

        if (maxNums == maxLine / 2)
        {
            maxNums--;
        }

        for (int num = maxNums; num > 0; num--)
        {
           cout << num; 
        }

        cout << endl;
    }
    return 0;
}