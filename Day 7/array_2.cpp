#include <iostream>
#include <vector>
#include <array>
#include <list>

int main() {
    // 1. C-Style String (Character Array)
    char greeting[] = "Hello, World!";
    std::cout << "C-Style String: " << greeting << std::endl;

    // Modifying a character in the C-Style String
    greeting[7] = 'C';
    std::cout << "Modified C-Style String: " << greeting << std::endl;

    // 2. C++ Standard Library Array (std::array)
    std::array<int, 5> stdArray = {5, 10, 15, 20, 25};
    std::cout << "\nstd::array elements:" << std::endl;
    for (int i = 0; i < stdArray.size(); i++) {
        std::cout << "stdArray[" << i << "] = " << stdArray[i] << std::endl;
    }

    // Using C++17 structured binding to iterate over std::array
    std::cout << "Using structured binding to iterate over std::array:" << std::endl;
    for (auto [index, value] : {std::pair(0, stdArray[0]), std::pair(1, stdArray[1]), 
                                std::pair(2, stdArray[2]), std::pair(3, stdArray[3]), 
                                std::pair(4, stdArray[4])}) {
        std::cout << "stdArray[" << index << "] = " << value << std::endl;
    }

    // 3. Vector (Dynamic Array, Resizable Array)
    std::vector<int> vectorArray = {100, 200, 300}; // Initializing with 3 elements
    vectorArray.push_back(400); // Adding an element to the end
    vectorArray.push_back(500); // Adding another element to the end
    std::cout << "\nstd::vector elements after adding two elements:" << std::endl;
    for (int i = 0; i < vectorArray.size(); i++) {
        std::cout << "vectorArray[" << i << "] = " << vectorArray[i] << std::endl;
    }

    // Removing the last element
    vectorArray.pop_back();
    std::cout << "std::vector after pop_back:" << std::endl;
    for (int i = 0; i < vectorArray.size(); i++) {
        std::cout << "vectorArray[" << i << "] = " << vectorArray[i] << std::endl;
    }

    // 4. Linked List (std::list)
    std::list<int> linkedList = {1, 2, 3, 4, 5}; // Initializing a linked list
    linkedList.push_back(6); // Add an element to the end
    linkedList.push_front(0); // Add an element to the front

    std::cout << "\nstd::list elements:" << std::endl;
    for (auto& element : linkedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Removing elements from linked list
    linkedList.pop_front(); // Remove the first element
    linkedList.pop_back();  // Remove the last element
    std::cout << "std::list after pop_front and pop_back:" << std::endl;
    for (auto& element : linkedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 5. Array of Pointers
    int a = 10, b = 20, c = 30;
    int* pointerArray[3] = {&a, &b, &c}; // Array of 3 pointers
    std::cout << "\nArray of Pointers:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "pointerArray[" << i << "] points to value: " << *pointerArray[i] << std::endl;
    }

    // 6. Array of Vectors (Dynamic subarrays)
    std::vector<int> vectorOfArrays[3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "\nArray of Vectors:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "vectorOfArrays[" << i << "]: ";
        for (int j = 0; j < vectorOfArrays[i].size(); j++) {
            std::cout << vectorOfArrays[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 7. Vector of Vectors (2D Dynamic Array)
    std::vector<std::vector<int>> vector2D = {{1, 2}, {3, 4, 5}, {6, 7, 8, 9}};
    std::cout << "\nVector of Vectors (2D Dynamic Array):" << std::endl;
    for (int i = 0; i < vector2D.size(); i++) {
        std::cout << "vector2D[" << i << "]: ";
        for (int j = 0; j < vector2D[i].size(); j++) {
            std::cout << vector2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
