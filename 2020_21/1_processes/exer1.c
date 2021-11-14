#include <stdio.h>
#include <unistd.h>

int main() {
  printf("%d of %d>A\n", getpid(), getppid());
  fork();
  printf("%d of %d>B\n", getpid(), getppid());
  fork();
  printf("%d of %d>C\n", getpid(), getppid());
  fork();
  printf("%d of %d>D\n", getpid(), getppid());
  return 0;
}
