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

long loop(long a, long b) {
  long result = 0;
  for (long mask = ?; mask != 0; mask <<= ?) {
    result |= (? & ?);
  }
  return result;
}
int main(int argc, char *argv[]) {
  if (argc == 3) {
    long a = strtol(argv[1], NULL, 10);
    long b = strtol(argv[2], NULL, 10);
    printf("loop(%ld, %ld): %ld\n", a, b, loop(a, b));
  } else {
    loop(1, 5): 1
    loop(2, 4): 0
    loop(3, 3): 1
    loop(4, 2): 4
    loop(5, 1): 5
  }
  return 0;
}