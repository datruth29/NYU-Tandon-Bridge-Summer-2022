#include <iostream>

using namespace std;


void printShiftedTriangle(int n, int m, char symbol)
{
    int spaces = m + (n - 1);
    int line;

    for (int row = 0; row < n; row++)
    {
        line = (2 * row) + 1;
        for (int col = 0; col < spaces; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < line; col++)
        {
            cout << symbol;
        }
        spaces--;
        cout << endl;
    }

}

void printPineTree(int n, char symbol)
{
    for (int tree = 2; tree <= n + 1; tree++)
    {
        printShiftedTriangle(tree, n - tree + 1, symbol);
    }
}

int main()
{
    int userTriangles;
    char userSymbol;

    cout << "How many triangles do you wish to be in your tree (needs to be greater than 2): ";
    cin >> userTriangles;
    cout << "What character would you like to appear on your tree?: ";
    cin >> userSymbol;

    printPineTree(userTriangles, userSymbol);
    return 0;
}