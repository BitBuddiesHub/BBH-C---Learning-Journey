#include <iostream>
#include <iomanip> // For std::hex and std::showbase

int main() {
    unsigned int a = -1; // Step 1: Assign -1 to `unsigned int a`
                         // This wraps around to `0xFFFFFFFF` in hexadecimal.
                         // Binary representation: 11111111 11111111 11111111 11111111
                         // Decimal equivalent: 4294967295

    unsigned int b = 2;  // Step 2: Set `b` to 2 for this example.

    // Step 3: Evaluate `b / 4`
    // Since `b` is 2, and we are performing integer division, `b / 4` results in `0`.
    // Division operator has higher precedence than XOR, so this is calculated first.

    unsigned int result = a ^ (b / 4); // Step 4: Perform the XOR operation
                                       // This simplifies to `a ^ 0` because `b / 4 = 0`.
                                       // a ^ 0 is equivalent to a, so `result = a`.
                                       // Since `a = 0xFFFFFFFF`, `result` is also 0xFFFFFFFF.

    // Output the values and the result in both decimal and hexadecimal formats
    std::cout << "Initial value of a (in decimal): " << a << std::endl;
    std::cout << "Initial value of a (in hexadecimal): " << std::showbase << std::hex << a << std::dec << std::endl;

    std::cout << "Value of b: " << b << std::endl;
    std::cout << "Result of b / 4: " << (b / 4) << std::endl;

    std::cout << "Result of a ^ (b / 4) (in decimal): " << result << std::endl;
    std::cout << "Result of a ^ (b / 4) (in hexadecimal): " << std::showbase << std::hex << result << std::dec << std::endl;

    return 0;
}
