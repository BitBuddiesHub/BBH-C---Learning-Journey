#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false; // Handle edge cases where num is less than 2
    int sqr = int(sqrt(num));
    for (int i = 2; i <= sqr; i++)
    { // Check divisors up to sqrt(num)
        if (num % i == 0)
        {
            return false; // If divisible, num is not a prime
        }
    }
    return true; // Return true if no divisors were found
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers from 1 to " << n << " are:" << endl;
    for (int i = 2; i <= n; i++) { // Start from 2, since 1 is not a prime number
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl; // Newline for clean output
    return 0;
}