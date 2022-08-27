#include <iostream>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    int i;

    for (i = 1; i * i < num; i++)
    {
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += i;
        }
    }

    if ((num / i) + 1 == i)
    {
        i--;
    }

    for (; i >= 1; i--)
    {
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += num / i;
        }
    }

    outCountDivs--;
    outSumDivs -= num;
}

bool isPerfect(int num)
{
    int count = 0, sum = 0;
    analyzeDividors(num, count, sum);
    return (num == sum);
}



int main()
{
    int iterations;

    cout << "Please enter a positive integer > 2: ";
    cin >> iterations;
    cout << endl << endl;

    int count = 0, sum = 0, pairCount = 0, pairSum = 0;

    cout << "Finding all perfect numbers...." << endl << endl;
    for (int i = 2; i <= iterations; i++)
    {
        if (isPerfect(i))
        {
            cout << i << " is perfect!" << endl;
        }
    }
    
    cout << endl;
    cout << "Finding all amicable pairs:...." << endl << endl;
    for (int i = 2; i <= iterations; i++)
    {

        analyzeDividors(i, count, sum);

        if (sum > i && sum < iterations)
        {
            //cout << i << " => " << sum;
            analyzeDividors(sum, pairCount, pairSum);
            if (i == pairSum )
            {
                cout << "(" << pairSum << ", " << sum << ")" << endl;
            }
            pairCount = 0;
            pairSum = 0;
        }

        count = 0;
        sum = 0;
    }

    return 0;
}
