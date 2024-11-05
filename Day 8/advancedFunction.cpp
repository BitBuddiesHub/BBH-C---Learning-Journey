// Example demonstrating advanced function concepts in C++

#include <iostream>
#include <functional>  // For std::function
using namespace std;

// Function demonstrating default arguments
void greet(string name = "Guest") {
    // If no argument is provided, the default value "Guest" is used
    cout << "Hello, " << name << "!" << endl;
}

// Function demonstrating function overloading
int multiply(int a, int b) {
    // Multiplies two integers and returns the result
    return a * b;
}

// Overloaded function with different parameter types
double multiply(double a, double b) {
    // Multiplies two doubles and returns the result
    return a * b;
}

// Function demonstrating function pointers
void callFunction(void (*funcPtr)(string), string arg) {
    // Calls the function pointed to by funcPtr with the given argument
    funcPtr(arg);
}

// Function to be passed as a pointer
void sayGoodbye(string name) {
    // Prints a goodbye message for the given name
    cout << "Goodbye, " << name << "!" << endl;
}

// Function demonstrating lambda expressions
void useLambda() {
    // Define a simple lambda that adds two numbers and returns the result
    auto add = [](int x, int y) -> int {
        return x + y;
    };

    // Use the lambda function to add two numbers and print the result
    cout << "Using lambda: 5 + 3 = " << add(5, 3) << endl;
}

// Function demonstrating std::function for function objects
void performOperation(int a, int b, std::function<int(int, int)> operation) {
    // Calls the provided operation function with arguments a and b, then prints the result
    cout << "Result of operation: " << operation(a, b) << endl;
}

int main() {
    // Demonstrate default arguments
    greet();  // Uses the default argument "Guest"
    greet("Alice");  // Uses the provided argument "Alice"

    // Demonstrate function overloading
    cout << "multiply(3, 4) = " << multiply(3, 4) << endl;  // Calls the version for integers
    cout << "multiply(3.5, 2.0) = " << multiply(3.5, 2.0) << endl;  // Calls the version for doubles

    // Demonstrate function pointers
    callFunction(sayGoodbye, "Bob");  // Calls sayGoodbye using a function pointer

    // Demonstrate lambda expressions
    useLambda();  // Calls the function using a lambda expression

    // Demonstrate std::function
    // Passes a lambda that subtracts two numbers to performOperation
    performOperation(10, 5, [](int x, int y) { return x - y; });

    return 0;
}
