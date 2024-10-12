#include <iostream>
#include <iomanip> // Required for setw
using namespace std;

int main() {
    // Displaying table headers with setw
    cout << setw(10) << "Name" << setw(10) << "Age" << setw(15) << "City" << endl;
    cout << "----------------------------------------" << endl;

    // Using setw to align table rows
    cout << setw(10) << "Alice" << setw(10) << 30 << setw(15) << "New York" << endl;
    cout << setw(10) << "Bob" << setw(10) << 25 << setw(15) << "Los Angeles" << endl;
    cout << setw(10) << "Charlie" << setw(10) << 28 << setw(15) << "Chicago" << endl;
    cout << setw(10) << "David" << setw(10) << 35 << setw(15) << "San Francisco" << endl;

    return 0;
}
