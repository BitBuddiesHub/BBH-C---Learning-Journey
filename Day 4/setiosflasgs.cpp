#include <iostream>
#include <iomanip> // Required for setiosflags
using namespace std;

int main() {
    double num1 = 123.456;
    double num2 = 78.9;

    // Using setiosflags to display fixed-point notation with showpoint
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Fixed-point notation with showpoint:" << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl << endl;

    // Reset flags
    cout << resetiosflags(ios::fixed | ios::showpoint);

    // Using setiosflags to display scientific notation with uppercase
    cout << setiosflags(ios::scientific | ios::uppercase);
    cout << "Scientific notation with uppercase:" << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl << endl;

    // Reset flags
    cout << resetiosflags(ios::scientific | ios::uppercase);

    // Using setiosflags for right alignment with showpos
    cout << setiosflags(ios::right | ios::showpos);
    cout << "Right alignment with showpos:" << endl;
    cout << setw(10) << num1 << endl;
    cout << setw(10) << num2 << endl << endl;

    // Reset flags
    cout << resetiosflags(ios::right | ios::showpos);

    // Using setiosflags for left alignment with field width
    cout << setiosflags(ios::left);
    cout << "Left alignment:" << endl;
    cout << setw(10) << num1 << setw(10) << num2 << endl;

    return 0;
}
