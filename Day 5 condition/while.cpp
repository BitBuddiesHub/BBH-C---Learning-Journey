#include <iostream>
using namespace std;

int main() {
    // Example 1: Infinite loop with `while`
    cout << "Example 1: Infinite while loop\n";
    int count = 0;
    while (true) {  // Condition always true
        cout << "Loop iteration: " << count << endl;
        count++;
        if (count >= 3) {
            break;  // Break out of the loop after 3 iterations
        }
    }

    // Example 2: Using `while` loop with no body
    cout << "\nExample 2: While loop with no body\n";
    int x = 0;
    while (x++ < 5);  // Empty body, loop ends when x reaches 5
    cout << "Final value of x after loop: " << x << endl;

    // Example 3: `do-while` loop that executes at least once, even if the condition is false
    cout << "\nExample 3: Do-while loop that executes at least once\n";
    int y = 10;
    do {
        cout << "Value of y: " << y << endl;
    } while (y < 5);  // The loop executes once even though y < 5 is false

    // Example 4: Self-modifying loop condition with `while`
    cout << "\nExample 4: Self-modifying while loop\n";
    int z = 1;
    while (z < 100) {
        cout << "Value of z: " << z << endl;
        z *= 2;  // Modify `z` within the loop body, causing exponential growth
    }

    // Example 5: Nested `do-while` loop to simulate a menu
    cout << "\nExample 5: Nested do-while loop as a simple menu\n";
    int option;
    do {
        cout << "Menu:\n";
        cout << "1. Say Hello\n";
        cout << "2. Say Goodbye\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Hello!\n";
                break;
            case 2:
                cout << "Goodbye!\n";
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
        }
    } while (option != 3);  // Loop until user chooses to exit

    // Example 6: Using `while` to create a countdown with a delay
    cout << "\nExample 6: Countdown with a delay\n";
    int countdown = 5;
    while (countdown > 0) {
        cout << "Countdown: " << countdown << endl;
        countdown--;
        // Introduce a small delay (this is a basic way to simulate delay)
        for (int i = 0; i < 100000000; i++);  // Busy-wait to create a delay
    }
    cout << "Blast off!\n";

    return 0;
}
