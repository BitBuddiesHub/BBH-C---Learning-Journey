// Main.cpp - Demonstrates how to simulate a multi-file structure within a single file in C++

// ------------------------------
// "MathFunctions.h" Simulation
// ------------------------------
#ifndef MATH_FUNCTIONS_H  // Include guard to prevent multiple inclusions
#define MATH_FUNCTIONS_H

// Declaration of the add function
int add(int a, int b);  // Adds two integers and returns the result

// Declaration of the multiply function
int multiply(int a, int b);  // Multiplies two integers and returns the result

#endif  // MATH_FUNCTIONS_H

// ------------------------------
// "MathFunctions.cpp" Simulation
// ------------------------------

// Definition of the add function
int add(int a, int b) {
    return a + b;  // Return the sum of a and b
}

// Definition of the multiply function
int multiply(int a, int b) {
    return a * b;  // Return the product of a and b
}

// ------------------------------
// Main Program
// ------------------------------

#include <iostream>  // Include the standard input-output library

using namespace std;

int main() {
    // Call the add function
    int sum = add(5, 3);
    cout << "5 + 3 = " << sum << endl;  // Output: 5 + 3 = 8

    // Call the multiply function
    int product = multiply(4, 6);
    cout << "4 * 6 = " << product << endl;  // Output: 4 * 6 = 24

    return 0;  // Return 0 to indicate successful program execution
}
