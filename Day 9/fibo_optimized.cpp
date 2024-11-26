#include <iostream>
using namespace std;

// Matrix multiplication for 2x2 matrices
void multiplyMatrix(long long a[2][2], long long b[2][2], long long mod = 1e9+7) {
    long long x = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    long long y = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    long long z = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    long long w = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;

    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;
}

// Fast exponentiation of the Fibonacci transformation matrix
void powerMatrix(long long mat[2][2], int n, long long mod = 1e9+7) {
    long long result[2][2] = {{1, 0}, {0, 1}}; // Identity matrix
    while (n > 0) {
        if (n % 2 != 0) {
            multiplyMatrix(result, mat, mod);
        }
        multiplyMatrix(mat, mat, mod);
        n /= 2;
    }
    mat[0][0] = result[0][0];
    mat[0][1] = result[0][1];
    mat[1][0] = result[1][0];
    mat[1][1] = result[1][1];
}

// Function to compute Fibonacci using matrix exponentiation
long long fibonacci(int n, long long mod = 1e9+7) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long fibMatrix[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(fibMatrix, n - 1, mod);
    return fibMatrix[0][0];
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci sequence: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative number." << endl;
        return 1;
    }

    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
