#include <iostream>
using namespace std;

enum Months
{
    JANUARY     = 1,
    FEBRUARY    = 2,
    MARCH       = 3,
    APRIL       = 4,
    MAY         = 5,
    JUNE        = 6,
    JULY        = 7,
    AUGUST      = 8,
    SEPTEMBER   = 9,
    OCTOBER     = 10,
    NOVEMBER    = 11,
    DECEMBER    = 12
};

const int DAYS_IN_WEEK      = 7;
const int MONTHS_IN_YEAR    = 12;


int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool isLeapYear(int year);
int getMonthInfo(int month, int year);

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

    // This is done because if the month did not end on a Sunday,
    // it wouldn't create a newline. This would throw off the display
    // days in a month.
    if (startingDay > 1)
    {
        cout << endl;
    }

    cout << endl;


    return startingDay;
}

void printYearCalender(int year, int startingDay)
{
    int daysInMonth;
    for (int month = 1; month <= MONTHS_IN_YEAR; month++)
    {
        daysInMonth = getMonthInfo(month, year);
        startingDay = printMonthCalender(daysInMonth, startingDay);
    }
}

bool isLeapYear(int year)
{
    bool result = ( (year % 4 != 0) ||
                    ((year % 100 == 0) && (year % 400 != 0)));
    return !result;
}

int getMonthInfo(int month, int year)
{
    int days;
    switch(month)
    {
        case JANUARY:
            cout << "January " << year << endl;
            days = 31;
            break;
        case FEBRUARY:
            cout << "February " << year << endl;
            if (isLeapYear(year))
            {
                days = 28;
            } else {
                days = 29;
            }
            break;
        case MARCH:
            cout << "March " << year << endl;
            days = 31;
            break;
        case APRIL:
            cout << "April " << year << endl;
            days = 30;
            break;
        case MAY:
            cout << "May " << year << endl;
            days = 31;
            break;
        case JUNE:
            cout << "June " << year << endl;
            days = 30;
            break;
        case JULY:
            cout << "July " << year << endl;
            days = 31;
            break;
        case AUGUST:
            cout << "August " << year << endl;
            days = 31;
            break;
        case SEPTEMBER:
            cout << "September " << year << endl;
            days = 30;
            break;
        case OCTOBER:
            cout << "October " << year << endl;
            days = 31;
            break;
        case NOVEMBER:
            cout << "November " << year << endl;
            days = 30;
            break;
        case DECEMBER:
            cout << "December " << year << endl;
            days = 31;
            break;
        default:
            cout << "Something went horribly wrong" << endl;
            return -1;
            break;
    }

    return days;
}


int main()
{
    printYearCalender(2016, 5);
    return 0;
}
