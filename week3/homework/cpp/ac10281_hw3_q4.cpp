#include<iostream>


using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
    float real_number;
    int rounding_method;

    cout << "Please enter a Real number:" << endl;
    cin >> real_number;

    cout << "Choose your rounding method:" << endl
    << "1. Floor round" << endl
    << "2. Ceiling round" << endl
    << "3. Round to the nearest whole number" << endl;
    cin >> rounding_method;

    // If the real number is negative, we decrease it by 1.
    if (real_number < 0)
    {
        real_number -= 1;
    }

    switch(rounding_method)
    {
        case(FLOOR_ROUND):
            cout << int(real_number);
        break;

        case(CEILING_ROUND):

            if ((real_number - int(real_number)) != 0)
            {
                cout << int(real_number)+1;
            }
            else
            {
                cout << int(real_number);
            }
        break;

        case(ROUND):
            cout << int(real_number+0.5);
        break;

        default:
        cout << "You selected an invalid option";
    }

    return 0;
}