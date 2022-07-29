#include<iostream>
#include<string>

using namespace std;

const float POUNDS_TO_KILOS = 0.45359237;
const float INCHES_TO_METERS = 0.0254;

int main()
{
    float weight, height;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;

    cout << "Please enter height (in inches): ";
    cin >> height;

    // Convert to kilograms
    weight *= POUNDS_TO_KILOS;
    
    // Convert to meters;
    height *= INCHES_TO_METERS;

    float bmi = weight/(height*height);
    string status;

    if ((weight < 0) || (height <= 0))
    {
        status = "Invalid. Enter valid weight/height values.";
    }
    else
    {
        if (bmi < 18.5)
        {
            status = "Underweight";
        }

        if (bmi >= 18.5 && bmi < 25)
        {
            status = "Normal";
        }
        if (bmi >= 25 && bmi < 30)
        {
            status = "Overweight";
        }
        if (bmi >= 30)
        {
            status = "Obese";
        }
    }

    cout << "The weight status is: " << status;

    return 0;
}