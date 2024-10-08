#include <iostream>

class MyClass {
public:
    int x;
    double y;
};

int main() {
    // Size of basic data types
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Size of char: " << sizeof(char) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";

    // Size of variables
    int a = 42;
    double b = 3.14;
    std::cout << "Size of variable a (int): " << sizeof(a) << " bytes\n";
    std::cout << "Size of variable b (double): " << sizeof(b) << " bytes\n";

    // Size of arrays
    int arr[10];
    std::cout << "Size of array arr: " << sizeof(arr) << " bytes\n";
    std::cout << "Number of elements in array arr: " << sizeof(arr) / sizeof(arr[0]) << "\n";

    // Size of custom class
    MyClass obj;
    std::cout << "Size of class MyClass: " << sizeof(MyClass) << " bytes\n";
    std::cout << "Size of object obj: " << sizeof(obj) << " bytes\n";

    // Size of pointer
    int* ptr = &a;
    std::cout << "Size of pointer ptr: " << sizeof(ptr) << " bytes\n";

    return 0;