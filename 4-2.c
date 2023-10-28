#include <stdio.h>
#include <stdlib.h>

long recursiveFact(long x);

int main(int argc, char *argv[]) {
  if (argc == 2) {
    long x = strtol(argv[1], NULL, 10);
    printf("iterativeFact(%ld): %ld\n", x, iterativeFact(x));
    printf("recursiveFact(%ld): %ld\n", x, recursiveFact(x));
  } else {
    iterativeFact(0): 1
    recursiveFact(0): 1
    iterativeFact(1): 1
    recursiveFact(1): 1
    iterativeFact(5): 120
    recursiveFact(5): 120
  }
  return 0;
}