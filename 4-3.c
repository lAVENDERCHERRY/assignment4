#include <stdio.h>
#include <stdlib.h>


// COPY .L3 ASSEMBLY CODE HERE:



// Transpose function that swaps elements in a 4x4 matrix
void transpose(long a[4][4]) {
    for (long i = 0; i < 4; i++) {
        for (long j = 0; j < i; j++) {
            // Store the value of a[i][j] in t1
            long t1 = a[i][j];
            // Store the value of a[j][i] in t2
            long t2 = a[j][i];
            // Swap the values of a[i][j] and a[j][i]
            a[i][j] = t2;
            a[j][i] = t1;
        }
    }
}

// Optimized transpose function using pointers to swap elements in a 4x4 matrix
void transposeOpt(long a[4][4]) {
    for (long i = 0; i < 4; ++i) {
        // Initialize rp (row pointer) to point to the start of the current row
        long *rp = &a[i][0];
        // Initialize cp (column pointer) to point to the start of the current column
        long *cp = &a[0][i];
        for (long j = 0; j < i; ++j) {
            // Swap data at rp and cp pointers without using temporary variables
            long temp = *rp;
            *rp = *cp;
            *cp = temp;
            
            // Increment rp to move to the next column in the current row
            rp++;
            // Increment cp to move to the next row in the current column
            cp += 4;  // Since it's a 4x4 matrix, you need to move to the next column.
        }
    }
}




void print(long a[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j =  0; j < 4; ++j) {
      printf("%ld ", a[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc == 17) {
    long a[4][4];
    long b[4][4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        a[i][j] = strtol(argv[i * 4 + j + 1], NULL, 10);
        b[i][j] = a[i][j];
      }
    }
    transpose(a);
    printf("transpose(a)\n");
    print(a);
    transposeOpt(b);
    printf("transposeOpt(b)\n");
    print(b);
  } else {
    // Test cases

    // Test case 1: A simple 4x4 matrix
    long testMatrix1[4][4] = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}};

    printf("Original Matrix 1:\n");
    print(testMatrix1);

    transposeOpt(testMatrix1);
    printf("Transposed Matrix 1:\n");
    print(testMatrix1);

    // Test case 2: Another 4x4 matrix
    long testMatrix2[4][4] = {{11, 12, 13, 14},
                              {15, 16, 17, 18},
                              {19, 20, 21, 22},
                              {23, 24, 25, 26}};

    printf("Original Matrix 2:\n");
    print(testMatrix2);

    transposeOpt(testMatrix2);
    printf("Transposed Matrix 2:\n");
    print(testMatrix2);
  }
  return 0;
}
