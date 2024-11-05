#include <iostream>
#include <algorithm> // For std::sort
#include <numeric>   // For std::accumulate

int main() {
    // 1. Declaring and Initializing an Array
    int numbers[5] = {10, 20, 30, 40, 50}; // Fixed-size array with 5 integers
    // The elements in this array are 10, 20, 30, 40, and 50.

    // 2. Accessing Array Elements
    std::cout << "Accessing elements in the array:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // 3. Modifying Array Elements
    numbers[2] = 100; // Changing the third element from 30 to 100
    std::cout << "\nAfter modifying the third element (index 2):" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // 4. Calculating the Sum of Array Elements
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i]; // Accumulate each element's value into sum
    }
    std::cout << "\nSum of array elements: " << sum << std::endl;

    // 5. Finding the Maximum and Minimum Elements
    int maxElement = numbers[0];
    int minElement = numbers[0];
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > maxElement) {
            maxElement = numbers[i]; // Update max if current element is greater
        }
        if (numbers[i] < minElement) {
            minElement = numbers[i]; // Update min if current element is smaller
        }
    }
    std::cout << "Maximum element: " << maxElement << std::endl;
    std::cout << "Minimum element: " << minElement << std::endl;

    // 6. Sorting the Array (ascending order)
    std::sort(numbers, numbers + 5); // Sorts from the first to last element
    std::cout << "\nArray after sorting in ascending order:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // 7. Using std::accumulate for Sum (another way to sum array elements)
    int totalSum = std::accumulate(numbers, numbers + 5, 0); // Starting sum at 0
    std::cout << "\nSum using std::accumulate: " << totalSum << std::endl;

    // 8. Multi-dimensional Arrays (2D array example)
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; // 2 rows and 3 columns
    std::cout << "\n2D Array (matrix):" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 9. Dynamic Array using pointers (advanced topic)
    int* dynamicArray = new int[5]; // Allocate memory for 5 integers
    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = (i + 1) * 10; // Initialize each element to 10, 20, 30, etc.
    }
    std::cout << "\nDynamic Array elements:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "dynamicArray[" << i << "] = " << dynamicArray[i] << std::endl;
    }
    delete[] dynamicArray; // Free allocated memory

    return 0;
}
