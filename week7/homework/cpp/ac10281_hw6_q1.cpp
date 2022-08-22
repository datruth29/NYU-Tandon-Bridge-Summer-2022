#include <iostream>
using namespace std;

const int LAST_DAY = 7;

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalendar(int year, int startingDay);
bool isLeapYear(int year);

int printMonthCalender(int numOfDays, int startingDay)
{
    cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

    if (startingDay > 1)
    {

        // Tab through missing days
        for (int i = 1; i < startingDay; i++)
        {
            cout << "\t";
        }
    }

    int days = 1;

    while (days <= numOfDays)
    {
        cout << days << "\t";

        if (startingDay % 7 == 0)
        {
            startingDay = 0;
            cout << endl;
        }

        days++;
        startingDay++;

    }

    return startingDay;
}

bool isLeapYear(int year)
{
    bool result = ( (year % 4 != 0) ||
                    ((year % 100 == 0) && (year % 400 != 0)));
    return !result;
}

void printYearCalender(int year, int startingDay)
{
    

}

int main()
{
    //int startDay = printMonthCalender(29, 7);
    //cout << endl << startDay;

    cout << isLeapYear(1896) << endl;
    cout << isLeapYear(1904) << endl;
    cout << isLeapYear(2000) << endl;
    cout << isLeapYear(1900) << endl;

    return 0;
}

