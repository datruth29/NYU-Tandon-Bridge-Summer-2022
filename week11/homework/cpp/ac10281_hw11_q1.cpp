#include <iostream>
using namespace std;

const char SYMBOL = '*';
const char MARK = '-';

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);


int main() {

    //printTriangle(4);
    //printOpositeTriangles(4);
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    if (n <= 0) {
        return;
    }
    printTriangle(n - 1);

    for (int i = 0; i < n; i++) {
        cout << SYMBOL;
    }
    cout << endl;
}

void printOpositeTriangles(int n) {
    if (n <= 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << SYMBOL;
    }

    cout << endl;

    printOpositeTriangles(n - 1);

    for (int i = 0; i < n; i++) {
        cout << SYMBOL;
    }

    cout << endl;

}

void printRuler(int n) {
    if (n <= 0 ) {
        return;
    }
    
    if (n == 1) {
        cout << MARK << endl;
        return;
    }

    printRuler(n-1);

    for (int i = 0; i < n; i++) {
        cout << MARK;
    }

    cout << endl;

    printRuler(n-1);


}