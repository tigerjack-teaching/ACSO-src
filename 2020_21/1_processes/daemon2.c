#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid1, pid2;
  pid1 = fork();
  if (pid1 == 0) {
    while (1) {
      printf("Hello\n");
      sleep(1);
    }
  }
  return 0;
}
