#include <iostream>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void test_isPerfect();

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    int i;

    for (i = 1; i * i < num; i++)
    {
        if (num % i == 0)
        {
//            cout << i << " ";
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
//            cout << num / i << " ";
            outCountDivs++;
            outSumDivs += num / i;
        }
    }

    outCountDivs--;
    outSumDivs -= num;

    //cout << endl << "Divisors: " << outCountDivs << " Sum: " << outSumDivs << endl;

}

bool isPerfect(int num)
{
    int count = 0, sum = 0;
    analyzeDividors(num, count, sum);
    return (num == sum);
}



int main()
{
    int count = 0, sum = 0, pairCount = 0, pairSum = 0;
    int iterations = 1000000;

    for (int i = 2; i <= iterations; i++)
    {
        if (isPerfect(i))
        {
            cout << i << " is perfect!";
        }
        analyzeDividors(i, count, sum);

        if (sum > i && sum < iterations)
        {
            //cout << i << " => " << sum;
            analyzeDividors(sum, pairCount, pairSum);
            //cout << " => " << pairSum << endl;
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

void test_isPerfect()
{
    for (int i = 2; i < 10000000; i++)
    {
        if (isPerfect(i))
            cout << i << " is Perfect!" << endl;
    }
}