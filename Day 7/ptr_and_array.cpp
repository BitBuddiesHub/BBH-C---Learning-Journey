#include <iostream>

int main() {
    // 1. Declaring and Initializing an Array
    int arr[5] = {10, 20, 30, 40, 50}; // Fixed-size array of integers

    // 2. Accessing Array Elements Using Array Indexing
    std::cout << "Accessing array elements using array indexing:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // 3. Accessing Array Elements Using Pointer Arithmetic
    std::cout << "\nAccessing array elements using pointer arithmetic:" << std::endl;
    int* ptr = arr; // ptr now points to the first element of arr (same as &arr[0])
    for (int i = 0; i < 5; i++) {
        std::cout << "*(ptr + " << i << ") = " << *(ptr + i) << std::endl;
    }

    // 4. Demonstrating that arr is essentially a pointer to the first element
    std::cout << "\nThe address of arr (array) and ptr (pointer to arr):" << std::endl;
    std::cout << "arr = " << arr << " (address of the first element in arr)" << std::endl;
    std::cout << "ptr = " << ptr << " (address held by ptr)" << std::endl;
    std::cout << "&arr[0] = " << &arr[0] << " (address of arr[0])" << std::endl;

    // 5. Difference between arr and ptr
    std::cout << "\nsizeof(arr) vs sizeof(ptr):" << std::endl;
    std::cout << "sizeof(arr) = " << sizeof(arr) << " bytes" << std::endl;
    std::cout << "sizeof(ptr) = " << sizeof(ptr) << " bytes" << std::endl;
    // Explanation: sizeof(arr) gives the total size of the array (5 * sizeof(int)),
    // whereas sizeof(ptr) gives the size of the pointer (typically 4 or 8 bytes).

    // 6. Modifying Array Elements Using Pointers
    *(ptr + 2) = 100; // Changes the third element of arr to 100
    std::cout << "\nArray after modifying the third element via pointer:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    return 0;
}
