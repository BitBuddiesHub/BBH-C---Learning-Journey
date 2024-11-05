#include <iostream>
using namespace std;

int main() {
    int year;

    // Prompt the user to enter a year
    cout << "Enter a year: ";
    cin >> year;

    // Determine if the year is a leap year
    if (year % 400 == 0) {
        cout << year << " is a leap year." << endl;
    } else if (year % 100 == 0) {
        cout << year << " is not a leap year." << endl;
    } else if (year % 4 == 0) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
