#include <iostream>
using namespace std;

// Optimized function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n; // Directly return for n = 0 or n = 1

    int a = 0, b = 1; // Initialize F(0) = 0, F(1) = 1
    for (int i = 2; i <= n; ++i) {
        b += a;  // Update b to the next Fibonacci number
        a = b - a; // Update a to the old value of b
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci sequence: ";
    cin >> n;

    // Handle invalid input (optional, depends on your use case)
    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative number." << endl;
        return 1;
    }

    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
