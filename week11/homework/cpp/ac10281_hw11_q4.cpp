#include <iostream>
using namespace std;

int jumpIt(int arr[], int arrSize);

int main() {
    int board[6] = {0, 3, 80, 6, 57, 10};
    cout << jumpIt(board, 6);
    return 0;
}

int jumpIt(int arr[], int arrSize) {
    if (arrSize <= 0) {
        return 0;
    }

    if (arrSize == 1) {
        return arr[arrSize-1];
    }

    if (arrSize == 2) {
        return arr[arrSize - 2] + arr[arrSize - 1];
    }

    int firstChoice = arr[0] + jumpIt(arr + 1, arrSize - 1);
    int secondChoice = arr[0] + jumpIt(arr + 2, arrSize - 2);

    if (firstChoice <= secondChoice) {
        return firstChoice;
    } else {
        return secondChoice;
    }

}