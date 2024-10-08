#include <iostream>
using namespace std;

int main() {
    // Arithmetic Expressions
    int a = 10, b = 3;
    cout << "Arithmetic Expressions:" << endl;
    cout << "Addition: " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << endl;
    cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << endl;
    cout << "Division: " << a << " / " << b << " = " << (a / b) << endl;
    cout << "Modulo: " << a << " % " << b << " = " << (a % b) << endl;
    cout << endl;

    // Relational Expressions
    int x = 10, y = 20;
    cout << "Relational Expressions:" << endl;
    cout << "Is x > y? " << (x > y) << endl;
    cout << "Is x < y? " << (x < y) << endl;
    cout << "Is x == y? " << (x == y) << endl;
    cout << "Is x != y? " << (x != y) << endl;
    cout << endl;

    // Logical Expressions
    bool p = true, q = false;
    cout << "Logical Expressions:" << endl;
    cout << "p && q = " << (p && q) << endl;
    cout << "p || q = " << (p || q) << endl;
    cout << "!p = " << (!p) << endl;
    cout << "!q = " << (!q) << endl;
    cout << endl;

    // Compound Expressions
    cout << "Compound Expressions:" << endl;
    cout << "Is (x + y) > 10? " << ((x + y) > 10) << endl;
    cout << "Is (x + 5) < y AND x != y? " << (((x + 5) < y) && (x != y)) << endl;
    cout << endl;

    // Assignment Expressions
    cout << "Assignment Expressions:" << endl;
    int z = 5;
    z = 10;
    cout << "After assignment, z = " << z << endl;
    z += 5;
    cout << "After z += 5, z = " << z << endl;
    z *= 2;
    cout << "After z *= 2, z = " << z << endl;
    cout << endl;

    // Ternary Operator
    cout << "Ternary Operator Expression:" << endl;
    int max = (a > b) ? a : b;
    cout << "The larger number between a and b is " << max << endl;
    cout << endl;

    // Bitwise Expressions
    cout << "Bitwise Expressions:" << endl;
    int m = 5, n = 3;
    cout << "m & n = " << (m & n) << endl;
    cout << "m | n = " << (m | n) << endl;
    cout << "m ^ n = " << (m ^ n) << endl;
    cout << "m << 1 = " << (m << 1) << endl;
    cout << "m >> 1 = " << (m >> 1) << endl;

    return 0;
}
