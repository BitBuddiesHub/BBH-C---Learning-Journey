// Example demonstrating global and local variables in C++

#include <iostream>
using namespace std;

// Global Variable
// This variable is accessible throughout the entire program
int globalCounter = 0;

// Function to increment the global variable
void incrementGlobalCounter() {
    globalCounter++;  // Incrementing the global variable
    cout << "Global counter is now: " << globalCounter << endl;
}

// Function to demonstrate the use of a local variable
void demonstrateLocalVariable() {
    // Local Variable
    // This variable is only accessible within this function
    int localCounter = 0;

    // Incrementing the local variable
    localCounter++;
    cout << "Local counter inside the function is: " << localCounter << endl;
}

int main() {
    // Accessing and using the global variable
    cout << "Initial global counter: " << globalCounter << endl;
    incrementGlobalCounter();  // Calling the function to increment the global variable

    // Demonstrating the use of a local variable
    demonstrateLocalVariable();  // Local variable only exists within this function call
    demonstrateLocalVariable();  // Each function call creates a new local variable

    // Attempting to access the local variable outside its scope would cause an error
    // Uncommenting the line below will result in a compilation error:
    // cout << "Trying to access localCounter: " << localCounter << endl;

    return 0;
}
