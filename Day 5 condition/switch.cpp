#include <iostream>
using namespace std;

int main() {
    // Declare a character variable to hold the user's grade input
    char grade;

    // Prompt the user to enter a grade
    cout << "Enter your grade (A, B, C, D, F): ";
    cin >> grade;  // Store the input in the variable 'grade'

    // Switch statement to handle different grade cases
    switch (grade) {
        case 'A':
        case 'a':  // Handle both uppercase and lowercase
            cout << "Excellent! You've earned an A." << endl;
            break;
        case 'B':
        case 'b':  // Handle both uppercase and lowercase
            cout << "Good job! You've earned a B." << endl;
            break;
        case 'C':
        case 'c':  // Handle both uppercase and lowercase
            cout << "You passed with a C." << endl;
            break;
        case 'D':
        case 'd':  // Handle both uppercase and lowercase
            cout << "You barely passed with a D." << endl;
            break;
        case 'F':
        case 'f':  // Handle both uppercase and lowercase
            cout << "Unfortunately, you've failed with an F." << endl;
            break;
        default:
            // This block executes if none of the above cases match
            cout << "Invalid grade entered. Please enter A, B, C, D, or F." << endl;
            break;
    }

    return 0;  // End of the program
}
