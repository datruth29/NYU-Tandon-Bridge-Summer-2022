// Name: Adam Collado
// NetId: ac10281

#include <iostream>

using namespace std;

const int TENS = 10;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;

int main()
{
	int userInput;
	int temp;
	int number;
	int digits = 0;
	int three_digits = 0;
	int four_digits = 0;
	int five_digits = 0;
	int six_digits = 0;
	int seven_digits = 0;
	int more_odd = 0;
	int equal_digits = 0;
	int even = 0;
	int odd = 0;

	cout << "Please enter a sequence of numbers (with at least 3-digits and at most 7-digits)"
		 << " each one in a separate line. End your sequence by typing -1:" << endl;

	while (true)
	{
		cin >> userInput;

		if (userInput == -1)
		{
			break;
		}

		temp = userInput;

		while (temp > 0)
		{
			number = temp % TENS;
			temp = temp / TENS;
			if (number % TWO == 0)
			{
				even++;
			}
			else
			{
				odd++;
			}
			digits++;
		}
		switch (digits)
		{
		case THREE:
			three_digits++;
			break;
		case FOUR:
			four_digits++;
			break;
		case FIVE:
			five_digits++;
			break;
		case SIX:
			six_digits++;
			break;
		case SEVEN:
			seven_digits++;
			break;
		default:
			break;
		}

		if (odd > even)
		{
			more_odd++;
		}
		else if (odd == even)
		{
			equal_digits++;
		}

		digits = 0;
		number = 0;
		temp = 0;
		even = 0;
		odd = 0;
	}

	cout << "Total count of numbers in the 3-digits Numbers Group: " << three_digits << endl;
	cout << "Total count of numbers in the 4-digits Numbers Group: " << four_digits << endl;
	cout << "Total count of numbers in the 5-digits Numbers Group: " << five_digits << endl;
	cout << "Total count of numbers in the 6-digits Numbers Group: " << six_digits << endl;
	cout << "Total count of numbers in the 7-digits Numbers Group: " << seven_digits << endl;
	cout << "Total count of numbers in the More Odd-digits Numbers Group: " << more_odd << endl;
	cout << "Total count of numbers in the Equal-digits Numbers Group: " << equal_digits << endl;

	cout << "Thank you!";
	return 0;
}