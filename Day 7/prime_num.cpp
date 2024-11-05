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

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPrime(n))
    {
        cout << "是素数"; // Output if the number is prime
    }
    else
    {
        cout << "不是素数"; // Output if the number is not prime
    }
    return 0;
}
