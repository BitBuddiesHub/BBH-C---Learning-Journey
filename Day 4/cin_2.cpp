#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    // Using cin.get() to read a single character
    char initial;
    cout << "Enter the first letter of your name: ";
    initial = cin.get(); // Reads a single character (including whitespace characters)
    cout << "Your initial: " << initial << endl;

    // Using cin.ignore() to skip the newline character left in the input buffer
    cin.ignore(100, '\n'); // Ignores up to 100 characters or until a newline is found

    // Using cin.getline() to read a full line of text
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName); // Reads the entire line until a newline character is encountered
    cout << "Full Name: " << fullName << endl;

    // Using cin.peek() to inspect the next character
    cout << "Enter your favorite number: ";
    char nextChar = cin.peek(); // Peeks at the next character without removing it from the buffer
    cout << "The next character you will input is: " << nextChar << endl;

    // Reading the integer input
    int favoriteNumber;
    cin >> favoriteNumber;
    cout << "Favorite Number: " << favoriteNumber << endl;

    // Using cin.putback() to put a character back into the input stream
    cout << "Enter a single digit: ";
    char digit = cin.get();
    cin.putback(digit); // Puts the character back into the input stream
    cout << "Digit placed back in stream: " << cin.get() << endl; // Reads it again to confirm

    // Using cin.sync() to discard any remaining characters in the buffer
    cin.sync(); // Synchronizes and clears any unread input from the buffer

    // Demonstrating cin.fail() and clearing errors
    cout << "Enter an integer value: ";
    int value;
    cin >> value;
    if (cin.fail()) {
        cout << "Invalid input! Resetting input stream." << endl;
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
    } else {
        cout << "You entered: " << value << endl;
    }

    return 0;
}
