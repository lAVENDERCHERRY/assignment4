#include <stdio.h>
#include <stdlib.h>

// Iterative factorial function
long iterativeFact(long x) {
    // Initialize the result to 1
    long result = 1;

    // Loop from 1 to x, calculating the factorial
    for (long i = 1; i <= x; i++) {
        result = i; // Multiply the result by the current value of 'i'
    }

    return result;
}

// Recursive factorial function
long recursiveFact(long x) {
    // Base case: if x is 0 or 1, return 1
    if (x <= 1) {
        return 1;
    } else {
        // Recursive case: multiply x by the factorial of (x - 1)
        // This function calls itself with x-1, forming a chain of recursive calls
        // Each call calculates the factorial of a smaller number until it reaches the base case
        // The results are accumulated when the function calls return, building the final result
        return x * recursiveFact(x - 1);
    }
}


int main(int argc, char *argv[]) {
    // Check if there is one command-line argument
    if (argc == 2) {
        // Parse the command-line argument as a long integer
        long x = strtol(argv[1], NULL, 10);

        // Print the results of the iterative and recursive factorial functions
        printf("iterativeFact(%ld): %ld\n", x, iterativeFact(x));
        printf("recursiveFact(%ld): %ld\n", x, recursiveFact(x));
    } else {
        // Print test cases for both functions
        printf("iterativeFact(0): %ld\n", iterativeFact(0));
        printf("recursiveFact(0): %ld\n", recursiveFact(0));
        printf("iterativeFact(1): %ld\n", iterativeFact(1));
        printf("recursiveFact(1): %ld\n", recursiveFact(1));
        printf("iterativeFact(5): %ld\n", iterativeFact(5));
        printf("recursiveFact(5): %ld\n", recursiveFact(5));
    }
    return 0;
}