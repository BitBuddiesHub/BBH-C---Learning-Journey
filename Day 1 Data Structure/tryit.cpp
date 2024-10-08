#include <iostream> // Include the input/output stream library
using namespace std; // Allows you to use standard library objects without prefixing them with "std::"

// Function that returns the maximum of two integers
int max(int i, int j)
{
    // If the first number is greater than or equal to the second, return the first
    if (i >= j)
        return i;
    else
        // Otherwise, return the second number
        return j;
}

int main()
{
    // Print a prompt asking the user to input two integers
    cout << "input i,j: ";
    int i, j; // Declare two integer variables to store user input
    cin >> i >> j; // Read the input values from the user

    // Call the max function to find the larger of the two numbers and print the result
    cout << "Max number is: " << max(i, j) << endl;

    return 0; // Indicate that the program finished successfully
}
