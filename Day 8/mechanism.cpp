// Example illustrating function call mechanisms in C++

#include <iostream>
using namespace std;

// Function to swap two numbers using "Call by Value"
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}

// Function to swap two numbers using "Call by Reference"
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: a = " << a << ", b = " << b << endl;
}

// Function to swap two numbers using "Call by Pointer"
void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Inside swapByPointer: a = " << *a << ", b = " << *b << endl;
}

int main() {
    // Initializing variables
    int x = 10, y = 20;

    // Demonstrating "Call by Value"
    cout << "Before swapByValue: x = " << x << ", y = " << y << endl;
    swapByValue(x, y);  // Passes copies of x and y
    cout << "After swapByValue: x = " << x << ", y = " << y << endl;

    // Demonstrating "Call by Reference"
    cout << "\nBefore swapByReference: x = " << x << ", y = " << y << endl;
    swapByReference(x, y);  // Passes references of x and y
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;

    // Demonstrating "Call by Pointer"
    cout << "\nBefore swapByPointer: x = " << x << ", y = " << y << endl;
    swapByPointer(&x, &y);  // Passes addresses of x and y
    cout << "After swapByPointer: x = " << x << ", y = " << y << endl;

    return 0;
}
