#include <string>
#include <iostream>
using namespace std;

int main(){

 string inputString;

 cout << "Please enter a line of text: ";

 getline (cin, inputString);

 int stringLength = inputString.length();

 int markedNums[stringLength];

 markedNums[0] = 1;

for (int i = 0; i < stringLength; i++) {
    cout << markedNums[i] << endl;
}
}