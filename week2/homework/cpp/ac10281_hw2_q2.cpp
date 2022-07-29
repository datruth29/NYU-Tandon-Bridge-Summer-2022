#include <iostream>

using namespace std;

const int DOLLAR_VALUE = 100;
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKLE_VALUE = 5;

int main()
{
    int dollars, quarters, dimes, nickles, pennies, cents, total;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;

    cin >> dollars >> cents;
    
    total = (dollars * DOLLAR_VALUE) + cents;

    quarters = total / QUARTER_VALUE;
    total -= quarters * QUARTER_VALUE;

    dimes = total / DIME_VALUE;
    total -= dimes * DIME_VALUE;

    nickles = nickles / NICKLE_VALUE;
    total -= nickles * NICKLE_VALUE;

    pennies = total;


    cout << dollars << " dollars and " << cents << " cents are :" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickles << " nickles and " << pennies << " pennies";
    return 0;
}