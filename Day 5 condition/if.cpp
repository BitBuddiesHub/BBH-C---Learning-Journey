#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable to hold the user's age
    int age;

    // Prompt the user to enter their age
    cout << "Please enter your age: ";
    cin >> age;  // Store the input in the variable 'age'

    // If statement to check if the user is a minor
    if (age < 18) {
        // This block executes if the condition (age < 18) is true
        cout << "You are a minor." << endl;
    }
    // Else if statement to check if the user is a young adult
    else if (age >= 18 && age < 65) {
        // This block executes if the above condition is false
        // and this condition (age >= 18 && age < 65) is true
        cout << "You are an adult." << endl;
    }
    // Else statement to handle all other cases
    else {
        // This block executes if none of the above conditions are true
        cout << "You are a senior citizen." << endl;
    }

    // Additional example with nested condition
    // Here, we'll check if the person is old enough to drive
    if (age >= 16) {
        cout << "You are old enough to drive." << endl;
        
        // Nested if statement to check if the person is also old enough to vote
        if (age >= 18) {
            cout << "You are old enough to vote." << endl;
        }
        else {
            // This block executes if the person can drive but not vote
            cout << "You are not old enough to vote." << endl;
        }
    }
    else {
        // This block executes if the person is not old enough to drive
        cout << "You are not old enough to drive." << endl;
    }

    return 0;  // End of the program
}