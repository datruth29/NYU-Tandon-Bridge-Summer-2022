#include <iostream>

using namespace std;
int main()
{
	int userInput;

	cout << "Please enter a positive integer n: ";
	cin >> userInput;

	for (int j = 1; j <= userInput; j++)
	{
		for (int i = 1; i <= userInput; i++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
	return 0;
}