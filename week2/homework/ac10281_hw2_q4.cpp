#include <iostream>

using namespace std;

int main()
{
    int x, y;

    cout << "Please enter two positive integers, separated by a space: " << endl;
    cin >> x >> y;

    cout << x << " + " << y << " = " << x+y << endl;
    cout << x << " - " << y << " = " << x-y << endl;
    cout << x << " * " << y << " = " << x*y << endl;
    cout << x << " / " << y << " = " << (double) x/ (double) y << endl;
    cout << x << " div " << y << " = " << x/y << endl;
    cout << x << " mod " << y << " = " << x%y << endl;

    return 0;
}