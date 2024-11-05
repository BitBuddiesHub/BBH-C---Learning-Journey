#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double sinApprox(double x, int terms = 10) {
    double result = 0.0;
    for (int n = 0; n < terms; n++) {
        // Calculate the n-th term: (-1)^n * x^(2n+1) / (2n+1)!
        double term = (pow(-1, n) * pow(x, 2 * n + 1)) / factorial(2 * n + 1);
        result += term;
    }
    return result;
}

int main() {
    double x;
    int terms;
    cout << "Enter the value of x (in radians): ";
    cin >> x;
    cout << "Enter the number of terms for approximation: ";
    cin >> terms;

    double approx = sinApprox(x, terms);
    cout << "Approximate sin(" << x << ") using " << terms << " terms is: " << approx << endl;

    return 0;
}
