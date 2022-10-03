#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
int old_minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    int arr[2] = {1, 0};
    int res5, res6;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 <<' '<< res2 << endl; // should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4);    // arr+2 is equivalent to &(arr[2])
    cout << res3 <<' '<< res4 << endl; // should both be 3
    return 0;
}

int minInArray1(int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0;
    }
    
    if (arrSize == 1) {
        return arr[arrSize];
    }

    int min = minInArray1(arr, arrSize - 1);

    if (arr[arrSize-1] < min) {
        return arr[arrSize-1];
    } else {
        return min;
    }
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    if (low - high == 1) {
        if (arr[low] < arr[high])
            return arr[low];
        return arr[high];
    }

    int rec_result = minInArray2(arr, ++low, --high);
    int current_min;

    if (arr[low] < arr[high])
        current_min = arr[low];
    else
        current_min = arr[high];
    
    if (rec_result < current_min)
        return rec_result;
    else
        return current_min;
    
}

int old_minInArray2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    if (arr[low] < arr[high]) {
        return minInArray2(arr, low, --high);
    } else {
        return minInArray2(arr, ++low, high);
    }
}