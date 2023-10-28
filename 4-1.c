#include <stdio.h>
#include <stdlib.h>

//loop:
        //movq    %rsi, %rcx
        //movl    $1, %edx
        //movl    $0, %eax
//.L2:
        //testq   %rdx, %rdx
        //je      .L4
        //movq    %rdx, %r8
        //andq    %rdi, %r8
        //orq     %r8, %rax
        //salq    %cl, %rdx
        //jmp     .L2
//.L4:
        //ret

// Function to calculate a result by iterating through each bit of 'a'
long loop(long a, long b) {
    // Initialize the result to 0
    long result = 0;

    // Start a loop with 'mask' initialized to 1
    // as long as mask does not = 0. we continue the loop
    // each iteration, we shift left by 2 bits
    for (long mask = 1; mask != 0; mask <<= 2) {
        // Check if the current bit in 'a' (indicated by 'mask') is set (1)
        if (mask & a) {
            // If the bit is set in 'a', perform a bitwise AND operation between 'mask' and 'b',
            // and then perform a bitwise OR operation with the 'result'
            result |= (mask & b);
        }
    }

    // Return the final result
    return result;
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        // If two command-line arguments are provided, parse them as long integers
        long a = strtol(argv[1], NULL, 10);
        long b = strtol(argv[2], NULL, 10);

        // Print the result of the 'loop' function for the provided inputs
        printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));
    } else {
        // If not enough arguments are provided, print the results of 'loop' for specific test cases
        printf("loop(1, 5): %ld\n", loop(1, 5));
        printf("loop(2, 4): %ld\n", loop(2, 4));
        printf("loop(3, 3): %ld\n", loop(3, 3));
        printf("loop(4, 2): %ld\n", loop(4, 2));
        printf("loop(5, 1): %ld\n", loop(5, 1));
    }

    return 0;
}