#include <iostream>
#include <bitset> // For displaying binary representation of integers

int main() {
    int a = 5; // Binary: 00000101
    int b = 3; // Binary: 00000011

    // Bitwise NOT (~)
    // ~a inverts each bit in `a`:
    // a:         00000101 (binary for 5)
    // ~a:        11111010 (inverted bits)
    // Result: -6 (in two's complement representation)
    int notA = ~a;
    std::cout << "Bitwise NOT of a (~a): " << notA << " (Binary: " << std::bitset<8>(notA) << ")" << std::endl;

    // Bitwise OR (|)
    // a | b compares each bit:
    // a:         00000101
    // b:         00000011
    // Result:    00000111 (1 if either bit is 1)
    // Decimal result is 7.
    int orResult = a | b;
    std::cout << "Bitwise OR of a and b (a | b): " << orResult << " (Binary: " << std::bitset<8>(orResult) << ")" << std::endl;

    // Bitwise AND (&)
    // a & b compares each bit:
    // a:         00000101
    // b:         00000011
    // Result:    00000001 (1 only if both bits are 1)
    // Decimal result is 1.
    int andResult = a & b;
    std::cout << "Bitwise AND of a and b (a & b): " << andResult << " (Binary: " << std::bitset<8>(andResult) << ")" << std::endl;

    // Bitwise XOR (^)
    // a ^ b compares each bit:
    // a:         00000101
    // b:         00000011
    // Result:    00000110 (1 if bits are different)
    // Decimal result is 6.
    int xorResult = a ^ b;
    std::cout << "Bitwise XOR of a and b (a ^ b): " << xorResult << " (Binary: " << std::bitset<8>(xorResult) << ")" << std::endl;

    // Left Shift (<<)
    // a << 1 shifts the bits of `a` left by one position:
    // a:         00000101
    // a << 1:    00001010 (each bit moves left; rightmost bit becomes 0)
    // Decimal result is 10.
    int leftShift = a << 1;
    std::cout << "Left Shift a by 1 (a << 1): " << leftShift << " (Binary: " << std::bitset<8>(leftShift) << ")" << std::endl;

    // Right Shift (>>)
    // a >> 1 shifts the bits of `a` right by one position:
    // a:         00000101
    // a >> 1:    00000010 (each bit moves right; leftmost bit becomes 0)
    // Decimal result is 2.
    int rightShift = a >> 1;
    std::cout << "Right Shift a by 1 (a >> 1): " << rightShift << " (Binary: " << std::bitset<8>(rightShift) << ")" << std::endl;

    // Combined operation example
    // (a & b) | (~a) ^ (b << 1):
    // Step-by-step:
    // 1. a & b:
    //    a:          00000101
    //    b:          00000011
    //    a & b:      00000001
    // 2. ~a:
    //    a:          00000101
    //    ~a:         11111010
    // 3. b << 1:
    //    b:          00000011
    //    b << 1:     00000110
    // 4. (~a) ^ (b << 1):
    //    ~a:         11111010
    //    b << 1:     00000110
    //    ~a ^ b<<1:  11111100
    // 5. (a & b) | ((~a) ^ (b << 1)):
    //    a & b:      00000001
    //    (~a ^ b<<1) 11111100
    //    Result:     11111101 (binary for -3 in two's complement)
    int combinedResult = (a & b) | (~a) ^ (b << 1);
    std::cout << "Combined operation (a & b) | (~a) ^ (b << 1): " << combinedResult << " (Binary: " << std::bitset<8>(combinedResult) << ")" << std::endl;

    return 0;
}
