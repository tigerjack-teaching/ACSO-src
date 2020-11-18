#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid1, pid2;
  pid1 = fork();
  if (pid1 == 0){
    pid2 = fork();
    if (pid2 == 0){
      while (1) {
        printf("Hello\n");
        sleep(1);
      }
    }
  }
  else{
    waitpid(pid1, NULL, 0);
    printf("Child exited\n");
  }

  return 0;
}
