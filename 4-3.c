#include <stdio.h>
#include <stdlib.h>

void transposeOpt(long a[4][4]) {
  for (long i = 0; i < 4; ++i) {
    long *rp = &a[i][0];
    long *cp = &a[0][i];
    for (long j = 0; j < i; ++j) {
      // TODO - swap data at rp, cp pointers, increment rp, cp
      // (as shown in the optimized x86-64 code above)
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
    printf("trasnposeOpt(b)\n");
    print(b);
  } else {
    // TODO - your test cases go here!
  }
  return 0;
}