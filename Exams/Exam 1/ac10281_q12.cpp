// Name: Adam Collado
// NetId: ac10281

#include <iostream>

using namespace std;

int main()
{
	int userInput;
	int stars;
	int spaces;

	cout << "Please enter a positive integer: " << endl;
	cin >> userInput;

	int line = 2 * userInput;

	for (int ast = 0; ast < line; ast++)
	{
		cout << "*";
	}

	cout << endl;

	for (int row = 1; row < line; row++)
	{
		if (row <= line / 2)
		{
			stars = row;
		}
		else
		{
			stars = line - row;
		}
		spaces = line - (row*2);

		if (spaces < 0)
		{
			spaces *= -1;
		}


		for (int col = 0; col < stars; col++)
		{
			cout << "*";
		}

		for (int space = 0; space < spaces; space++)
		{
			cout << " ";
		}

		for (int col = 0; col < stars; col++)
		{
			cout << "*";
		}

		cout << endl;
	}

	for (int ast = 0; ast < line; ast++)
	{
		cout << "*";
	}

	cout << endl;
	return 0;
}