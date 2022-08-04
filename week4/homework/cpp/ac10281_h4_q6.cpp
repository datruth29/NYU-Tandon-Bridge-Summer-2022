#include <iostream>

using namespace std;

int main()
{
    int userInput;
    int currentTotal;
    int evenCount;
    int oddCount;

    cout << "Please enter a positive integer: ";
    cin >> userInput;

    for(int i = 1; i <= userInput; i++)
    {
        currentTotal = i;
        evenCount = 0;
        oddCount = 0;

        while (currentTotal > 0)
        {
            if (currentTotal % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }

            currentTotal /= 10;
        }

        if (evenCount > oddCount)
        {
            cout << i << endl;
        }
    }
    return 0;
}