#include <iostream>
#include <cmath>

using namespace std;

double _eApprox(int n)
{
    return pow((1+1.0/n), n);
}

double eApprox (int n)
{
    double result = 1;
    double denominator = 1;

    for (int i = 1; i <= n; i++)
    {
        denominator *= double(i);
        result += 1/denominator;
    }

    return result;
}

int main()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}