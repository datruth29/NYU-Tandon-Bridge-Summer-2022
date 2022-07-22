#include<iostream>
#include<string>

using namespace std;

int main()
{
    string user_name;
    int graduation_year;
    int current_year;

    cout << "Please enter your name: ";
    cin >> user_name;

    cout << "Please enter your graduation year: ";
    cin >> graduation_year;

    cout << "Please enter your current year: ";
    cin >> current_year;

    int year_difference = graduation_year - current_year;
    string status;

    if (year_difference <= 0)
    {
        status = "Graduated";
    }
    else if (year_difference == 1)
    {
        status = "a Senior";
    }
    else if (year_difference == 2)
    {
        status = "a Junior";
    }
    else if (year_difference == 3)
    {
        status = "a Sophomore";
    }
    else if (year_difference == 4)
    {
        status = "a Freshmen";
    }
    else
    {
        status = "not in college yet";
    }

    cout << user_name << " you are " << status << endl;

    return 0;
}