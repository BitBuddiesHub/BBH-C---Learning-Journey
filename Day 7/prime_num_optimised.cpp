#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    // Step 1: Create a boolean vector and initialize all entries as true.
    // Initially, assume all numbers are prime
    vector<bool> isPrime(n + 1, true);
    
    // Step 2: Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;

    // Step 3: Start marking multiples of each prime starting from 2
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) { // If i is still marked as prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    // Step 4: Print all prime numbers
    cout << "Prime numbers from 1 to " << n << " are:" << endl;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}
