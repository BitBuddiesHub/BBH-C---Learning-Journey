#include <iostream>
#include <iomanip> // Required for setprecision
using namespace std;

int main() {
    double pi = 3.141592653589793;

    // Display without setting precision
    cout << "Default precision: " << pi << endl;

    // Setting precision to 3 digits
    cout << "Precision 3: " << setprecision(3) << pi << endl;

    // Setting precision to 5 digits
    cout << "Precision 5: " << setprecision(5) << pi << endl;

    // Setting precision to 8 digits
    cout << "Precision 8: " << setprecision(8) << pi << endl;

    // Using fixed to control the number of digits after the decimal
    cout << fixed;
    cout << "Fixed, Precision 3: " << setprecision(3) << pi << endl;
    cout << "Fixed, Precision 5: " << setprecision(5) << pi << endl;

    // Using scientific notation
    cout << scientific;
    cout << "Scientific, Precision 3: " << setprecision(3) << pi << endl;
    cout << "Scientific, Precision 5: " << setprecision(5) << pi << endl;

    return 0;
}
