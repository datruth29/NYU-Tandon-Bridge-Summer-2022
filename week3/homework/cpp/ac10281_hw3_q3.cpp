#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    float a, b, c;

    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;

    float numerator = sqrt((b*b)-(4*a*c));

    if (a == 0 && b == 0 && c == 0)
    {
        cout << "This equation has an infinite number of solutions";
    }
    else if (a == 0 && b == 0)
    {
        cout << "This equation has no solution";
    }
    else if (isnan(numerator))
    {
        cout << "This equation has no real solutions";
    }
    else if (a == 0)
    {
        cout << "This equation has a single real solution x=" << (c/-b);
    }
    else if (numerator == 0)
    {
        cout << "This equation has a single real solution x=" << (-b+numerator)/(2*a);
    }
    else
    {
        cout << "This equation has two real solutions x=" << (-b+numerator)/(2*a) << " and x=" << (-b-numerator)/(2*a);
    }

    return 0;
}