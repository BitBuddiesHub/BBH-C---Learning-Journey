// Example of defining and calling functions in C++

// Including the standard library for input-output operations
#include <iostream>
using namespace std;

// Function definition: This function takes two integers and returns their sum
int add(int a, int b) {
    // Calculate and return the sum
    return a + b;
}

// Function definition: This function takes two integers and returns their product
int multiply(int a, int b) {
    // Calculate and return the product
    return a * b;
}

// Function definition: This function prints a welcome message
void printWelcomeMessage() {
    cout << "Welcome to the C++ function demonstration!" << endl;
}

// Main function: Entry point of the program
int main() {
    // Calling the function to print a welcome message
    printWelcomeMessage();

    // Declare two integer variables and initialize them
    int x = 5;
    int y = 10;

    // Call the 'add' function and store the result
    int sum = add(x, y);
    // Output the result of addition
    cout << "The sum of " << x << " and " << y << " is: " << sum << endl;

    // Call the 'multiply' function and store the result
    int product = multiply(x, y);
    // Output the result of multiplication
    cout << "The product of " << x << " and " << y << " is: " << product << endl;

    // Return 0 to indicate successful execution
    return 0;
}
