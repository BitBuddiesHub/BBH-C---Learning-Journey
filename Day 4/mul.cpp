#include <iostream>

int main() {
    int x = 5;           // Initial value to work with
    int result_mul;      // Variable to store the result of multiplication using `imul`
    int result_shift;    // Variable to store the result of multiplication using `shl` (left shift)

    // Multiplication using the `imul` instruction
    asm (
        "movl %[x], %%eax;"       // Load the value of `x` into the EAX register.
                                  // The EAX register is commonly used to hold intermediate results or return values.
        
        "movl $2, %%ecx;"         // Load the constant `2` into the ECX register.
                                  // This is the multiplier, and loading it into a register allows for faster access.

        "imul %%ecx, %%eax;"      // Multiply EAX by ECX (i.e., x * 2).
                                  // The result is stored in EAX. The `imul` instruction performs signed integer multiplication.
                                  // This is a more complex operation as it requires the CPU to use its multiplication circuits.
        
        "movl %%eax, %[result];"  // Move the result from EAX back into the `result_mul` variable.
                                  // This instruction places the value of EAX into our result variable.
        
        : [result] "=r" (result_mul) // Output operand: The result goes into `result_mul`.
                                     // The "=r" constraint tells the compiler to use a general-purpose register for the result.
        
        : [x] "r" (x)               // Input operand: The value of `x`.
                                     // The "r" constraint allows the compiler to use any register for the value of `x`.
        
        : "%eax", "%ecx"            // Clobbered registers: This informs the compiler that EAX and ECX are modified.
                                     // Clobbers ensure the compiler is aware these registers have been used, avoiding conflicts.
    );

    // Left Shift using the `shl` instruction
    asm (
        "movl %[x], %%eax;"       // Load the value of `x` into the EAX register.
                                  // This prepares EAX to be shifted to the left.
        
        "shl $1, %%eax;"          // Shift the bits in EAX left by 1 position (x << 1).
                                  // The `shl` instruction performs a logical left shift, moving all bits left and filling in a 0 on the right.
                                  // Shifting left by one position effectively multiplies the value by 2.
                                  // This operation is faster and simpler than `imul` because it only involves bit manipulation, not full multiplication.
        
        "movl %%eax, %[result];"  // Move the result from EAX back into the `result_shift` variable.
                                  // This stores the final shifted value back into our output variable.
        
        : [result] "=r" (result_shift) // Output operand: The result goes into `result_shift`.
                                       // The "=r" constraint specifies a general-purpose register for this variable.
        
        : [x] "r" (x)               // Input operand: The value of `x` again.
                                       // The "r" constraint allows the compiler to place `x` in any register.
        
        : "%eax"                    // Clobbered register: Only EAX is modified in this operation.
                                       // Declaring EAX as clobbered helps the compiler manage register usage effectively.
    );

    // Output the results
    std::cout << "Multiplying " << x << " by 2 using `imul`: " << result_mul << std::endl;
    std::cout << "Multiplying " << x << " by 2 using `shl`: " << result_shift << std::endl;

    return 0;
}
