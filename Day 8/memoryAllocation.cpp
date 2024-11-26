// Example demonstrating memory allocation and deallocation in C++

#include <iostream>
using namespace std;

// Function to allocate memory for an integer array
int* createArray(int size) {
    // Dynamically allocate memory for an array of integers using 'new'
    // 'new' allocates memory on the heap, which needs to be manually managed
    int* array = new int[size];  // Memory is allocated for 'size' integers
    cout << "Memory allocated for an array of size " << size << "." << endl;
    return array;  // Return the pointer to the allocated memory
}

// Function to release memory allocated for an array
void deleteArray(int* array) {
    // Deallocate the memory using 'delete[]'
    // 'delete[]' is used for deallocating arrays allocated with 'new'
    delete[] array;  // Free the allocated memory to avoid memory leaks
    cout << "Memory deallocated for the array." << endl;
}

// Function demonstrating the use of dynamic memory management
void memoryManagementExample() {
    // Call createArray to allocate memory for an array of 5 integers
    int* myArray = createArray(5);

    // Use the allocated memory (initialize and print array elements)
    for (int i = 0; i < 5; i++) {
        myArray[i] = i * 10;  // Assign values to the array elements
        cout << "myArray[" << i << "] = " << myArray[i] << endl;  // Print each element
    }

    // Call deleteArray to deallocate the memory
    // This is crucial to avoid memory leaks, as the allocated memory will not be automatically freed
    deleteArray(myArray);
}

// Main function: Entry point of the program
int main() {
    // Call the function that demonstrates memory allocation and deallocation
    memoryManagementExample();

    // Return 0 to indicate successful program execution
    return 0;
}
