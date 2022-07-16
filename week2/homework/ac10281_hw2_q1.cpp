#include <iostream>

using namespace std;

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
    
    quarters = quarters * 25;
    dimes = dimes * 10;
    nickles = nickles * 5;
    total = quarters + dimes + nickles + pennies;

    dollars = total / 100;
    cents = total - (dollars * 100);

    cout << "The total is " << dollars << " dollars and " << cents << " cents";
    return 0;
}