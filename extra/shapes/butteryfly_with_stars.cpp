#include <iostream>

using namespace std;

int main()
{
    int userInput;
    int spaces;
    cout << "Please enter a positive integer: ";
    cin >> userInput;


    int maxLine = userInput * 2;
    int maxStars;
    int maxSpaces;

    for (int row = 0; row < maxLine - 1; row++)
    {
        if (row + 1 <= maxLine / 2)
        {
            maxStars = row + 1;
        }
        else
        {
            maxStars = maxLine - row - 1;
        }

        maxSpaces = (maxLine - 1) - (2 * maxStars) ;

        for (int num = 1; num <= maxStars; num++)
        {
           cout << "*"; 
        }
        
        for (int spaces = 0; spaces < maxSpaces; spaces++)
        {
            cout << " ";
        }

        if (maxStars == maxLine / 2)
        {
            maxStars--;
        }

        for (int num = maxStars; num > 0; num--)
        {
           cout << "*"; 
        }

        cout << endl;
    }
    return 0;
}