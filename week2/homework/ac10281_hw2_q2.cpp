#include <iostream>

using namespace std;

int main()
{
    int dollars, quarters, dimes, nickles, pennies, cents, total;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";

    cin >> dollars >> cents;
    
    total = (dollars * 100) + cents;

    quarters = total / 25;
    total -= quarters * 25;

    dimes = total / 10;
    total -= dimes * 10;

    nickles = nickles / 5;
    total -= nickles * 5;

    pennies = total;


    cout << dollars << " dollars and " << cents << " cents are :\n";
    cout << quarters << " quarters, " << dimes << " dimes, " << nickles << " nickles and " << pennies << " pennies";
    return 0;
}