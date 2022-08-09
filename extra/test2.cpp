#include<iostream>

using namespace std;

const int INCHES_IN_FEET = 12;
const int FEET_IN_YARDS = 3;
int main()
{
    int user_input = 0;
    int days = 0;
    int inches = 0;

    while (true)
    {
        cout << "Enter the number of inches the snail traveled in day #" << days << "or type -1 if they reached their destination:" << endl;
        cin >> user_input;
        if (user_input == -1)
        {
            break;
        }

        inches+=user_input;
        days++;
    }

    if (days != 0)
    {
        int yards;
        int feet;

        feet = inches/INCHES_IN_FEET;
        inches -= feet*INCHES_IN_FEET;

        yards = feet/FEET_IN_YARDS;
        feet -= yards*FEET_IN_YARDS;

        cout << "In " << days << " days, the snail travels " << yards << " yards, " << feet << " feet and " << inches << " inches.";
    }
    else
    {
        cout << "Snail never traveled and just stood still.";
    }
    return 0;
}