// PreprocessorDemo.cpp - Demonstrates the use of preprocessor directives in C++

#include <iostream>  // Include the standard input-output library
using namespace std;

// ------------------------------
// Preprocessor Directives
// ------------------------------

// Macro Definition: Defining constants using #define
#define PI 3.14159  // This defines a macro named PI with the value 3.14159

// Macro Function: A macro that calculates the square of a number
#define SQUARE(x) ((x) * (x))  // This defines a macro function to calculate the square of x

// Conditional Compilation: Using #ifdef, #ifndef, #else, and #endif
#define DEBUG_MODE  // Uncomment or comment this line to enable/disable debug mode

// Include Guard: Simulating an include guard to prevent multiple inclusions
#ifndef MY_HEADER_H  // Check if MY_HEADER_H is not defined
#define MY_HEADER_H  // Define MY_HEADER_H to prevent further inclusions

// Function Declarations (Simulating a header file)
void showPI();  // Function to display the value of PI
void calculateSquare(int number);  // Function to calculate and display the square of a number

#endif  // End of include guard

// ------------------------------
// Function Definitions
// ------------------------------

// Function to display the value of PI
void showPI() {
    cout << "The value of PI is: " << PI << endl;
}

// Function to calculate and display the square of a number using the SQUARE macro
void calculateSquare(int number) {
    cout << "The square of " << number << " is: " << SQUARE(number) << endl;
}

// ------------------------------
// Main Program
// ------------------------------

int main() {
    // Using the macro PI
    showPI();  // Call the function to display PI

    // Using the macro function SQUARE
    int number = 5;
    calculateSquare(number);  // Call the function to calculate and display the square

    // Conditional Compilation: Code included only if DEBUG_MODE is defined
#ifdef DEBUG_MODE
    cout << "Debug mode is enabled." << endl;
#else
    cout << "Debug mode is disabled." << endl;
#endif

    return 0;  // Return 0 to indicate successful program execution
}
