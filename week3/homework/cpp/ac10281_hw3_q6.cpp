#include<iostream>
#include<string>

using namespace std;

const float WEEKEND_RATE = .15;
const float ON_HOURS_RATE = .40;
const float OFF_HOURS_RATE = .25;

int main()
{
    int hours, minutes, caller_minutes;
    char semi;
    string day_of_the_week;

    cout << "Please enter the time the call took place (24-hour notation): ";
    cin >> hours >> semi >> minutes;

    cout << "Please enter the day this took place using the first two letters of the day: ";
    cin >> day_of_the_week;

    cout << "Please enter the number of minutes the call lasted: ";
    cin >> caller_minutes;

    float total = 0;

    if ((day_of_the_week == "Su") ||(day_of_the_week == "Sa"))
    {
        total = caller_minutes * WEEKEND_RATE;
    }
    else if ((hours < 8) || (hours >= 18))
    {
        total = caller_minutes * OFF_HOURS_RATE;
        cout << "Off Hours " << hours;
    }
    else
    {
        total = caller_minutes * ON_HOURS_RATE;
        cout << "On Hours: " << hours;
    }

    cout << "Total Cost of Call: " << total;
    

    return 0;
}