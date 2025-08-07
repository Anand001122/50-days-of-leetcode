#include <iostream>

using namespace std;

int main(){
    int num1, num2;

    //Get input for the first number 
    cout << "Enter the first number: ";
    cin >> num1;

    //Get input for second number
    cout << "Enter the second number: ";
    cin >> num2;

    //Calculate and display the sum
    int sum = num1 + num2;
    cout << "Sum: " << sum << endl;

    return 0;
}