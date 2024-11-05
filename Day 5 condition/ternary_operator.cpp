#include <iostream>
using namespace std;

int main()
{
    // Declare variables to store user input and results
    int number;
    string result;

    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> number;

    // Use the ternary operator to determine if the number is even or odd
    result = (number % 2 == 0) ? "Even" : "Odd";

    // Output the result
    cout << "The number is " << result << "." << endl;

    // Additional example: Use nested ternary operator to categorize the number
    string description = (number > 0) ? "Positive" : (number < 0 ? "Negative" : "Zero");

    // Output the description
    cout << "The number is " << description << "." << endl;

    return 0;
}
