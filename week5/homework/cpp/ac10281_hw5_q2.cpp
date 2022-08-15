#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_GUESSES = 5;

int main()
{
	srand(time(0));
	int secretNumber = (rand() % 100) + 1;
	int guessesLeft = MAX_GUESSES;
	int userGuess;
	int lowGuess = 1;
	int highGuess = 100;
	bool result = false;

	while (guessesLeft >= 1)
	{
		cout << "Range[" << lowGuess << ", " << highGuess << "], Number of guesses left: " << guessesLeft << endl;
		cout << "Your guess: ";
		cin >> userGuess;
		guessesLeft--;

		if (userGuess > 100 || userGuess < 1)
		{
			cout << "That's outside the range! Guess a number between 1 and 100." << endl;
			cin >> userGuess;
			continue;
		}
		if (userGuess == secretNumber)
		{
			result = true;
			break;
		}
		if (userGuess > secretNumber)
		{
			if (highGuess >= userGuess)
			{
				highGuess = userGuess - 1;
			}
			cout << "Wrong! My numbers is smaller." << endl << endl;
		}
		if (userGuess < secretNumber)
		{
			if (lowGuess <= userGuess)
			{
				lowGuess = userGuess + 1;
			}
			cout << "Wrong! My number is larger." << endl << endl;
		}

	}

	if (result)
	{
		cout << "Congrats! You guessed my number in " << MAX_GUESSES - guessesLeft << " guesses.";
	}
	else
	{
		cout << "Out of guesses! My number is " << secretNumber;
	}


	return 0;
}