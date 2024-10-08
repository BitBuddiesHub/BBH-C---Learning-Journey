#include <iostream>
using namespace std;

int main() {
    int a = 5;   // 'a' is initialized to 5
    int b = 10;  // 'b' is initialized to 10
    int c;       // 'c' is declared but not initialized

    // Comma operator example:
    // This line has three expressions separated by the comma operator:
    // - (a += 3): This adds 3 to 'a'. Since 'a' is initially 5, a becomes 8.
    // - (b -= 2): This subtracts 2 from 'b'. Since 'b' is initially 10, b becomes 8.
    // - (a * b): This multiplies the updated 'a' and 'b' values. Since both 'a' and 'b' are now 8, the result is 64.
    // The result of the whole expression (a += 3, b -= 2, a * b) is the last part, 'a * b', which is 64.
    c = (a += 3, b -= 2, a * b); 

    // Output the values of 'a', 'b', and 'c'
    cout << "a: " << a << endl;  // Outputs 8: 'a' was incremented by 3.
    cout << "b: " << b << endl;  // Outputs 8: 'b' was decremented by 2.
    cout << "c: " << c << endl;  // Outputs 64: 'c' is assigned the result of 'a * b'.

    return 0;
}
