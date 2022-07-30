#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sequence;
    double geoMean = 0;
    double total = 0;

    cout << "Section A: For Loop" << endl << endl;
    cout << "Please enter the length of the sequence: ";
    cin >> sequence;

    cout << "Please enter your sequence: " << endl;
    for (int i = 0; i < sequence; i++)
    {
        int number;
        cin >> number;

        if (total == 0)
        {
            total = number;
        }
        else
        {
            total *= number;
        }
    }

    geoMean = pow(total , 1.0 / sequence);
    cout << "The geometric mean is: " << geoMean << endl;

    sequence = 0;
    geoMean = 0;
    total = 0;
    int count = 0;

    cout << "Section B: While Loop" << endl << endl;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
    cin >> sequence;
    while (sequence != -1)
    {

        if (total == 0)
        {
            total = sequence;
        }
        else
        {
            total *= sequence;
        }

        count++;
        cin >> sequence;
    }

    geoMean = pow(total , 1.0 / count);
    cout << "The geometric mean is: " << geoMean << endl;
    return 0;

}