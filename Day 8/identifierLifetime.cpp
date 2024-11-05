// Example demonstrating storage types and identifier lifetimes in C++

#include <iostream>
using namespace std;

// Global variable: Storage type is "static" by default
// Lifetime: Entire duration of the program
int globalVar = 100;

// Function demonstrating the use of an automatic variable (default for local variables)
void automaticVariableExample() {
    // Automatic variable (default storage type for local variables)
    int autoVar = 10;  // Lifetime: Created when function is called, destroyed when function exits
    cout << "Inside automaticVariableExample: autoVar = " << autoVar << endl;
}

// Function demonstrating the use of a static variable
void staticVariableExample() {
    // Static variable retains its value between function calls
    static int staticCounter = 0;  // Lifetime: Entire duration of the program
    staticCounter++;
    cout << "Inside staticVariableExample: staticCounter = " << staticCounter << endl;
}

// Function demonstrating the use of an external variable
extern int externalVar;  // Declared using the "extern" keyword; defined elsewhere

// Function demonstrating the use of a register variable
void registerVariableExample() {
    // Register variable (suggests storing the variable in a CPU register for faster access)
    register int registerVar = 50;  // Note: Modern compilers may ignore this hint
    cout << "Inside registerVariableExample: registerVar = " << registerVar << endl;
}

int main() {
    // Accessing the global variable
    cout << "In main: globalVar = " << globalVar << endl;

    // Calling a function with an automatic variable
    automaticVariableExample();

    // Calling a function with a static variable multiple times
    staticVariableExample();
    staticVariableExample();
    staticVariableExample();

    // Using the external variable (defined in the same file for simplicity)
    cout << "In main: externalVar = " << externalVar << endl;

    // Calling a function with a register variable
    registerVariableExample();

    return 0;
}

// Definition of the external variable
int externalVar = 200;
