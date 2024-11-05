#include <iostream>

int main() {
    // 1. Array Index Out of Bounds
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Array Index Out of Bounds Error:" << std::endl;
    std::cout << "arr[5] = " << arr[5] << std::endl; // Accessing an index outside the array size
    
    // Explanation:
    // In C++, there's no bounds checking for arrays, so accessing arr[5] is undefined behavior.
    // This can lead to unexpected results, crashes, or accessing invalid memory.
    // To avoid this error, always ensure that index values are within bounds (0 to size - 1).

    // 2. Uninitialized Array Elements
    int uninitializedArr[3]; // Array declared without initialization
    std::cout << "\nUninitialized Array Elements Error:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "uninitializedArr[" << i << "] = " << uninitializedArr[i] << std::endl;
    }

    // Explanation:
    // If we don't initialize array elements, they contain "garbage values" (random values).
    // This can lead to errors if we expect meaningful data in the array.
    // To avoid this error, always initialize the array (e.g., int uninitializedArr[3] = {0};).

    // 3. Array Size Misinterpretation
    int anotherArr[5] = {10, 20, 30}; // Only three elements initialized
    std::cout << "\nArray Size Misinterpretation Error:" << std::endl;
    std::cout << "Array size is 5, but we only initialized 3 elements." << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "anotherArr[" << i << "] = " << anotherArr[i] << std::endl;
    }

    // Explanation:
    // In this case, only the first three elements are initialized, and the rest are zero-initialized.
    // Some developers mistakenly assume that uninitialized elements are random values.
    // To avoid issues, be explicit about the intended size and initialize all elements if needed.

    // 4. Using sizeof() on a Pointer Instead of an Array
    int* dynamicArr = new int[5]{1, 2, 3, 4, 5}; // Dynamically allocated array
    std::cout << "\nsizeof() on a Pointer Instead of an Array:" << std::endl;
    std::cout << "sizeof(dynamicArr) = " << sizeof(dynamicArr) << " bytes" << std::endl;
    std::cout << "sizeof(arr) = " << sizeof(arr) << " bytes" << std::endl;

    // Explanation:
    // sizeof(dynamicArr) only returns the size of the pointer (4 or 8 bytes), not the array size.
    // This can be an error if we mistakenly assume it's giving us the array's length.
    // Use a separate variable to store the array size when working with dynamic arrays.

    // 5. Dangling Pointer After Array Deletion
    delete[] dynamicArr; // Freeing the dynamically allocated memory
    std::cout << "\nDangling Pointer Error:" << std::endl;
    std::cout << "Attempting to access deleted dynamicArr[0]: " << dynamicArr[0] << std::endl;

    // Explanation:
    // After deleting dynamicArr, accessing its elements is undefined behavior and can cause crashes.
    // To avoid this error, set the pointer to nullptr after deletion:
    // delete[] dynamicArr;
    // dynamicArr = nullptr;

    // 6. Incorrect Array Initialization (Incorrect number of braces)
    int incorrectInitArr[2][2] = {1, 2, 3, 4}; // Incorrect for a 2D array
    std::cout << "\nIncorrect Array Initialization:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << "incorrectInitArr[" << i << "][" << j << "] = " << incorrectInitArr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Explanation:
    // Initializing a 2D array requires braces for each row to be clearly separated: {{1, 2}, {3, 4}}.
    // If we skip braces, it may work, but it's considered incorrect and can cause issues in complex cases.
    // To avoid this, initialize 2D arrays as int arr[2][2] = {{1, 2}, {3, 4}}.

    return 0;
}
