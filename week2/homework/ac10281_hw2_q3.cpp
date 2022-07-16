#include <iostream>

using namespace std;

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

    cout << "\n\nPlease enter the number of days Bill has worked: ";
    cin >> input; 
    days += input;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> input; 
    hours += input;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> input; 
    minutes += input; 

    hours += minutes / 60;
    minutes = minutes % 60;

    days += hours / 24;
    hours = hours % 24;

    cout << "\n\nThe total time both of them worked together is: " << days << " days, " << hours << " hours and " << minutes << " minutes.";

    return 0;
}