#include<iostream>
#include<string>

using namespace std;

const float WEEKEND_RATE = .15;
const float ON_HOURS_RATE = .40;
const float OFF_HOURS_RATE = .25;
const int MINUTES_IN_HOUR = 60;

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

    int start_time = (hours * MINUTES_IN_HOUR) + minutes;

    if ((day_of_the_week == "Su") ||(day_of_the_week == "Sa"))
    {
        total = caller_minutes * WEEKEND_RATE;
    }
    else if ((start_time >= 8 * MINUTES_IN_HOUR) && (start_time <= 18 * MINUTES_IN_HOUR))
    {
        total = caller_minutes * ON_HOURS_RATE;
    }
    else
    {
        total = caller_minutes * OFF_HOURS_RATE;
    }

    cout << fixed << showpoint;
    cout.precision(2);
    cout << "Total Cost of Call: " << total;

    return 0;
}