#include <stdio.h>
#include <unistd.h>

int main() {
  printf("A\n");
  fork();
  printf("B\n");
  fork();
  printf("C\n");
  fork();
  printf("D\n");
  return 0;
}
