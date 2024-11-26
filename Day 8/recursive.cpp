// Example demonstrating recursion in C++

#include <iostream>
using namespace std;

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
    // Base case: If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n * factorial(n - 1)
    return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    // Base case: Return n if it is 0 or 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Recursive case: fibonacci(n - 1) + fibonacci(n - 2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Demonstrate recursive factorial calculation
    int num = 5;
    // The factorial of a number is the product of all positive integers less than or equal to that number
    // For example, 5! = 5 * 4 * 3 * 2 * 1 = 120
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    // Demonstrate recursive Fibonacci calculation
    int fibIndex = 6;
    // The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones
    // Starting from 0 and 1, the sequence is: 0, 1, 1, 2, 3, 5, 8, ...
    // For example, the 6th Fibonacci number is 8
    cout << "Fibonacci number at index " << fibIndex << " is: " << fibonacci(fibIndex) << endl;

    return 0;
}
