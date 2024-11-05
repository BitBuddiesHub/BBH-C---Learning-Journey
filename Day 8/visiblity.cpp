// Example demonstrating scope, visibility, and shadowing of identifiers in C++

#include <iostream>
using namespace std;

// Global variable: Visible throughout the entire file
int globalValue = 42;

// Function demonstrating visibility of global variables
void showGlobalValue() {
    cout << "Inside showGlobalValue: globalValue = " << globalValue << endl;
}

// Another function demonstrating shadowing and nested block scope
void shadowingExample() {
    // Local variable with the same name as the global variable
    int globalValue = 10;  // This shadows the global globalValue
    cout << "Inside shadowingExample: globalValue (local) = " << globalValue << endl;

    // Nested block
    {
        int innerValue = 5;  // Block-scoped variable only visible in this block
        cout << "Inside nested block: innerValue = " << innerValue << endl;
        cout << "Inside nested block: globalValue (still local) = " << globalValue << endl;

        // Modifying the shadowed local globalValue in the nested block
        globalValue += innerValue;
        cout << "After modifying: globalValue (local) = " << globalValue << endl;
    }

    // Attempting to access innerValue outside the nested block will result in an error
    // cout << "Outside nested block: innerValue = " << innerValue << endl; // Uncommenting this line will cause a compilation error

    // The local globalValue is still accessible and has the modified value
    cout << "Outside nested block: globalValue (local) = " << globalValue << endl;
}

// Function demonstrating block scope in loops
void loopScopeExample() {
    for (int i = 0; i < 3; i++) {
        cout << "Inside loop: i = " << i << endl;
    }

    // Attempting to access i outside the loop will result in an error
    // cout << "Outside loop: i = " << i << endl; // Uncommenting this line will cause a compilation error

    // Declaring a new variable named i outside the loop is allowed
    int i = 10;
    cout << "Outside loop, new i = " << i << endl;
}

// Function demonstrating variable lifetime and static variables
void staticVariableExample() {
    static int staticCounter = 0;  // Static variable retains its value between function calls
    staticCounter++;
    cout << "staticCounter = " << staticCounter << endl;
}

int main() {
    // Accessing the global variable in main
    cout << "In main: globalValue = " << globalValue << endl;

    // Calling a function that uses the global variable
    showGlobalValue();

    // Calling a function that demonstrates shadowing
    shadowingExample();

    // Demonstrating block scope in loops
    loopScopeExample();

    // Demonstrating the lifetime of a static variable
    staticVariableExample();
    staticVariableExample();
    staticVariableExample();  // Each call increments staticCounter

    return 0;
}
