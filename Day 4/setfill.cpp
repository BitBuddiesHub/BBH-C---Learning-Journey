#include <iostream>
#include <iomanip> // Required for setfill and setw
using namespace std;

int main() {
    // Using setfill('*') to fill empty space with '*'
    cout << setfill('*') << setw(10) << 123 << endl;

    // Using setfill('-') to fill empty space with '-'
    cout << setfill('-') << setw(10) << 45.67 << endl;

    // Using setfill('0') to fill empty space with '0' for zero-padding
    cout << setfill('0') << setw(10) << 89 << endl;

    // Resetting setfill back to spaces
    cout << setfill(' '); // Default fill character

    // Printing a formatted table with padded fields
    cout << setfill('.') << setw(15) << left << "Product" 
         << setw(10) << right << "Price" << endl;
    cout << setfill('.') << setw(15) << left << "Apple" 
         << setw(10) << right << "$1.20" << endl;
    cout << setfill('.') << setw(15) << left << "Banana" 
         << setw(10) << right << "$0.50" << endl;
    cout << setfill('.') << setw(15) << left << "Cherry" 
         << setw(10) << right << "$2.00" << endl;

    return 0;
}
