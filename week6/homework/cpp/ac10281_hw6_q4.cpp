#include <iostream>

using namespace std;

void printDivisors (int num);

void printDivisors(int num)
{
    int div;

    for (div = 1; div * div < num; div++)
    {
        if (num % div == 0)
        {
            cout << div << " ";
        }
    }
    if ((num / div) + 1 == div)
    {
        div--;
    }
    for (; div >= 1; div--)
    {
        if (num % div == 0)
        {
            cout << num / div << " ";
        }
    }
}

int main()
{
    int userInput;

    cout << "Please enter a positive integer >= 2: ";
    cin >> userInput;

    printDivisors(userInput);

    return 0;
}