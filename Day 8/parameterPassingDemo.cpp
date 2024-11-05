// ParameterPassingDemo.cpp - Demonstrates different types of parameter passing in C++

#include <iostream>
using namespace std;

// Function demonstrating "Pass by Value"
void passByValue(int num) {
    // The parameter 'num' is a copy of the argument passed
    // Modifying 'num' will not affect the original variable
    num += 10;
    cout << "Inside passByValue: num = " << num << endl;
}

// Function demonstrating "Pass by Reference"
void passByReference(int &num) {
    // The parameter 'num' is a reference to the original argument
    // Modifying 'num' will change the original variable
    num += 10;
    cout << "Inside passByReference: num = " << num << endl;
}

// Function demonstrating "Pass by Pointer"
void passByPointer(int *num) {
    // The parameter 'num' is a pointer to the original argument
    // Using '*num' to modify the value at the memory address will change the original variable
    *num += 10;
    cout << "Inside passByPointer: *num = " << *num << endl;
}

int main() {
    // Initial value of the variable
    int value = 5;

    // ----------------------
    // Pass by Value Example
    // ----------------------
    cout << "Original value before passByValue: " << value << endl;
    passByValue(value);  // Passes a copy of 'value'
    cout << "Original value after passByValue: " << value << endl;
    // The original 'value' is unchanged

    // ----------------------
    // Pass by Reference Example
    // ----------------------
    cout << "\nOriginal value before passByReference: " << value << endl;
    passByReference(value);  // Passes a reference to 'value'
    cout << "Original value after passByReference: " << value << endl;
    // The original 'value' is modified

    // ----------------------
    // Pass by Pointer Example
    // ----------------------
    cout << "\nOriginal value before passByPointer: " << value << endl;
    passByPointer(&value);  // Passes the address of 'value'
    cout << "Original value after passByPointer: " << value << endl;
    // The original 'value' is modified

    return 0;
}
