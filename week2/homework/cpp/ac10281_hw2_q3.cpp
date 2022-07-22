#include <iostream>

using namespace std;

const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;

int main()
{
    int days = 0, hours = 0, minutes = 0, total = 0, input;

    cout << "Please enter the number of days John has worked: ";
    cin >> input; 
    days += input;
    cout << "Please enter the number of hours John has worked: ";
    cin >> input; 
    hours += input;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> input; 
    minutes += input; 

    cout << endl << endl << "Please enter the number of days Bill has worked: ";
    cin >> input; 
    days += input;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> input; 
    hours += input;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> input; 
    minutes += input; 

    hours += minutes / MINUTES_IN_HOUR;
    minutes = minutes % MINUTES_IN_HOUR;

    days += hours / HOURS_IN_DAY;
    hours = hours % HOURS_IN_DAY;

    cout << endl << endl << "The total time both of them worked together is: "
    << days << " days, " << hours << " hours and " << minutes << " minutes.";

    return 0;
}