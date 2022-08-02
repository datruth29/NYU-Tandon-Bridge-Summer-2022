#include<iostream>

using namespace std;

int main()
{
    int userInputOne;
    int n;
    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;

    int index = 1;
    while (index <= n)
    {
        cout << index * 2 << endl;
        index++;
    }

    cout << endl;
    cout << "section b" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << i * 2 << endl;
    }
    return 0;
}