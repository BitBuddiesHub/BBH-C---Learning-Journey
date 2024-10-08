#include <iostream>
#include <iomanip> // For std::hex and std::showbase

int main() {
    unsigned int a = -1; // Step 1: Assign -1 to unsigned int `a`.
                         // In unsigned representation, -1 becomes 0xFFFFFFFF due to wrap-around.
                         // Binary representation of 0xFFFFFFFF: 11111111 11111111 11111111 11111111 (32 bits).
                         // Decimal equivalent: 4294967295.
                         
    unsigned int b = 2;  // Step 2: Set `b` to 2. This will determine the shift amount.
                         // We are using `b + 1` as the shift amount in the expression `a >> (b + 1)`.

    // Compute the result of `a >> (b + 1)`
    // - Since `b` is 2, `b + 1` equals 3.
    // - Right shift by 3 positions is equivalent to dividing `a` by 2^3 (or 8).
    unsigned int result = a >> (b + 1);

    // Explanation of the Shift Operation:
    // a:           0xFFFFFFFF    (Binary: 11111111 11111111 11111111 11111111)
    // a >> 3:      0x1FFFFFFF    (Shift each bit right by 3 positions)
    // - After shifting right by 3:
    //   Binary result: 00011111 11111111 11111111 11111111
    //   Hexadecimal result: 0x1FFFFFFF
    //   Decimal result: 536870911
    // - The shift removes the rightmost 3 bits and introduces zeros from the left.

    // Output the original value of `a`, the shift amount, and the final result.
    std::cout << "Initial value of a (in decimal): " << a << std::endl;
    std::cout << "Initial value of a (in hexadecimal): " << std::showbase << std::hex << a << std::dec << std::endl;

    std::cout << "Shift amount (b + 1): " << (b + 1) << std::endl;
    std::cout << "Result of a >> (b + 1) (in decimal): " << result << std::endl;
    std::cout << "Result of a >> (b + 1) (in hexadecimal): " << std::showbase << std::hex << result << std::dec << std::endl;

    return 0;
}
