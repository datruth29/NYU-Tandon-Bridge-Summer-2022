#include <iostream>

int max(int a, int b);
int maxSumArray(int arr[], int size);

int max (int a, int b)
{
    if (a > b) return a;
    else return b;
}

int maxSumArray(int arr[], int size)
{
    int bestSum = arr[0];
    int currentSum = bestSum;
    
    for (int i = 1; i < size; i++)
    {
        currentSum += arr[i];
        currentSum = max(currentSum, arr[i]);
        bestSum = max(currentSum, bestSum);
    }
    return bestSum;
}

int main()
{
    int foo [9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << maxSumArray(foo, 9);

    return 0;
}