#include <iostream>
#include <string>
#include <limits> // For numeric_limits
using namespace std;

int main() {
    // Basic integer input
    int age;
    cout << "Enter your age: ";
    cin >> age; // Reads an integer value into 'age'

    // Error handling for integer input
    if (cin.fail()) {
        cout << "Invalid input! Please enter a number." << endl;
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Basic floating-point input
    double height;
    cout << "Enter your height in cm: ";
    cin >> height; // Reads a floating-point value into 'height'
    
    if (cin.fail()) {
        cout << "Invalid input! Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Reading single-word strings
    string name;
    cout << "Enter your first name: ";
    cin >> name; // Reads a single word into 'name' (stops at whitespace)

    // Reading entire lines (including spaces)
    string fullName;
    cout << "Enter your full name: ";
    cin.ignore(); // Clear any leftover input in the buffer
    getline(cin, fullName); // Reads an entire line (up to newline) into 'fullName'

    // Reading multiple values in one line
    int day, month, year;
    cout << "Enter your birth date (day month year): ";
    cin >> day >> month >> year; // Reads three integers in a row

    // Error handling for reading multiple values
    if (cin.fail()) {
        cout << "Invalid input! Please enter the date in numbers." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Display all the input information
    cout << "\nYou entered the following information:\n";
    cout << "First Name: " << name << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Birth Date: " << day << "/" << month << "/" << year << endl;

    return 0;
}