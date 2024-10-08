#include <iostream>
using namespace std;

int main() {
    // Example: Implicit conversion from int to bool
    int x = 0;
    bool b1 = x;  // Implicit conversion
    cout << "x (int 0) converted to bool: " << b1 << endl;  // Output: 0 (false)

    x = 1;
    bool b2 = x;  // Implicit conversion
    cout << "x (int 1) converted to bool: " << b2 << endl;  // Output: 1 (true)

    // Example: Explicit conversion using static_cast
    int y = 5;
    bool b3 = static_cast<bool>(y);  // Explicit conversion
    cout << "y (int 5) converted to bool using static_cast: " << b3 << endl;  // Output: 1 (true)

    // Example: Using ternary operator to force conversion (manual control)
    int z = 0;
    bool b4 = (z == 0) ? false : true;  // Manual conversion
    cout << "z (int 0) manually converted to bool: " << b4 << endl;  // Output: 0 (false)

    return 0;
}
