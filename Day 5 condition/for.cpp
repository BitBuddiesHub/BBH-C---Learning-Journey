#include <iostream>
using namespace std;

int main() {
    // Example 1: Using multiple variables in the initialization and update sections
    cout << "Example 1: Multiple variables in initialization and update sections\n";
    for (int i = 0, j = 5; i < j; i++, j--) {
        cout << "i: " << i << ", j: " << j << endl;
    }

    // Example 2: Infinite loop using 'for'
    cout << "\nExample 2: Infinite loop\n";
    int count = 0;
    for (;;) {  // Equivalent to `while (true)`
        cout << "Loop iteration: " << count << endl;
        count++;
        if (count >= 3) {
            break;  // Exit the loop after 3 iterations
        }
    }

    // Example 3: Using a `for` loop without the increment section
    cout << "\nExample 3: Loop without increment section\n";
    for (int i = 1; i <= 5;) {
        cout << "i: " << i << endl;
        i += 2;  // Increment manually within the loop body
    }

    // Example 4: Empty loop body
    cout << "\nExample 4: Empty loop body\n";
    int sum = 0;
    for (int i = 1; i <= 5; sum += i++);  // All operations done in the condition
    cout << "Sum of numbers from 1 to 5: " << sum << endl;

    // Example 5: Declaring the loop variable outside the `for` loop
    cout << "\nExample 5: Variable declared outside the loop\n";
    int k;
    for (k = 0; k < 5; k++) {
        cout << "k: " << k << endl;
    }
    cout << "Final value of k after loop: " << k << endl;

    return 0;
}
