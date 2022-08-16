#include <iostream>

using namespace std;

unsigned int fib(unsigned int n);

int main()
{
    unsigned int userInput;

    cout << "Please enter a positive integer: ";
    cin >> userInput;

    cout << fib(userInput);

    return 0;
}

unsigned int fib(unsigned int n)
{
    unsigned int currentFib = 1;
    unsigned int prevFib = 1;
    unsigned int temp;
    int currentPlace = 3;

    if (n == 0)
    {
        return 0;
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    while (currentPlace <= n)
    {
        temp = currentFib;
        currentFib += prevFib;
        prevFib = temp;
        currentPlace++;
    }
    return currentFib;
}