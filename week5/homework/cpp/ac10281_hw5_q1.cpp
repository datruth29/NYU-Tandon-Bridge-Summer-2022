#include <iostream>

using namespace std;
int main()
{
	int userInput;
	int calculation;

	cout << "Please enter a positive integer n: ";
	cin >> userInput;

	for (int j = 1; j <= userInput; j++)
	{
		for (int i = 1; i <= userInput; i++)
		{
			calculation = i * j;
			
			cout << calculation;
			if (calculation >= 1000)
			{
				cout << " ";
			}
			else if (calculation >= 100)
			{
				cout << "  ";
			}
			else if (calculation >= 10)
			{
				cout << "   ";
			}
			else
			{
				cout << "    ";
			}



		}
		cout << endl;
	}
	return 0;

}