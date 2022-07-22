#include <iostream>

using namespace std;

const int DOLLAR_VALUE = 100;
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKLE_VALUE = 5;

int main()
{
    int dollars, quarters, dimes, nickles, pennies, cents, total;

    cout << "Please enter number of coins: " << endl;

    cout << "# of quarters:";
    cin >> quarters;
    cout << "# of dimes:";
    cin >> dimes;
    cout << "# of nickles:";
    cin >> nickles;
    cout << "# of pennies:";
    cin >> pennies;
    
    quarters = quarters * QUARTER_VALUE;
    dimes = dimes * DIME_VALUE;
    nickles = nickles * NICKLE_VALUE;
    total = quarters + dimes + nickles + pennies;

    dollars = total / DOLLAR_VALUE;
    cents = total - (dollars * DOLLAR_VALUE);

    cout << "The total is " << dollars << " dollars and " << cents << " cents";
    return 0;
}