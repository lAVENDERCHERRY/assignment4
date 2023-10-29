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

// Function that performs bitwise operations on two long integers 'a' and 'b'
long loop(long a, long b) {
    // Initialize the result variable to 0
    long result = 0;

    // Start a loop with 'mask' initialized to 5 and running until 'mask' is not 0
    // as long as mask is not 0, we loop 
    // each iteration, we shift left by 2 bits
    for (long mask = 5; mask != 0; mask <<= 2) {
        // Check if the current 'mask' bit is set in 'a'
        if (mask & a) {
            // If the bit is set in 'a', set the corresponding bit in 'result' as well
            result |= (mask & a);
        }
    }

    // Return the final result after the loop
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