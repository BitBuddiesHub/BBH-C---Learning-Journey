// Example of parameter passing, return values, and function declarations in C++

#include <iostream>
using namespace std;

// Function Declaration (Prototype)
// Declaring the function before the main function
int subtract(int, int);  // Function to subtract two integers
void greetUser(string);  // Function to greet the user
double calculateArea(double);  // Function to calculate the area of a circle

// Function to add two integers and return the sum
// This function demonstrates passing parameters by value
int add(int a, int b) {
    return a + b;  // Returning the sum
}

// Main function: Entry point of the program
int main() {
    // Declare variables
    int num1 = 8;
    int num2 = 3;

    // Calling the 'add' function
    int sum = add(num1, num2);
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    // Calling the 'subtract' function
    int difference = subtract(num1, num2);
    cout << "The difference between " << num1 << " and " << num2 << " is: " << difference << endl;

    // Calling the 'greetUser' function
    greetUser("Alice");

    // Calling the 'calculateArea' function
    double radius = 5.0;
    double area = calculateArea(radius);
    cout << "The area of a circle with radius " << radius << " is: " << area << endl;

    return 0;  // Successful program execution
}

// Function Definition: Subtract two integers and return the difference
// This demonstrates how parameters are passed by value
int subtract(int a, int b) {
    return a - b;  // Returning the difference
}

// Function Definition: Greet the user
// This demonstrates how to pass a string parameter by value
void greetUser(string name) {
    cout << "Hello, " << name << "! Welcome to the C++ function tutorial." << endl;
}

// Function Definition: Calculate the area of a circle
// This function returns a double and demonstrates passing a double parameter by value
double calculateArea(double radius) {
    return 3.14159 * radius * radius;  // Returning the calculated area
}
