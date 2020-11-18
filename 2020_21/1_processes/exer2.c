// printf, scanf
#include <stdio.h>
// exit
#include <stdlib.h>
// pid_t
#include <sys/types.h>
// posix api, including fork
#include <unistd.h>
// for wait
#include <sys/wait.h>

const int WAIT_ON = 1;

int main(int argc, char *argv[]) {
  pid_t pid1, pid2, pid_tmp;
  int somma = 0;
  int status;
  int tmp;
  pid1 = fork();
  printf("pid: %d\n", getpid());
  scanf("%d", &tmp);
  if (pid1 == 0) {
    // Child
    somma++;
    printf("[child1] exiting, somma is %d\n", somma);
    exit(somma);
  } else {
    somma++;
    pid2 = fork();
    printf("pid: %d\n", getpid());
    scanf("%d", &tmp);
    if (pid2 == 0) {
      somma++;
      printf("[child2] exiting, somma is %d\n", somma);
      exit(somma);
    } else {
      pid_tmp = waitpid(pid1, &status, 0);
      printf("pid1 is %d, pid2 is %d\n", pid1, pid2);
      printf("[parent] waitpid, pid returned %d\n", pid_tmp);
      printf("[parent] pid1 exit code was %d\n", status / 256);
      // Try htop without wait
      pid_tmp = wait(&status);
      printf("[parent] wait, pid returned %d\n", pid_tmp);
      printf("[parent] pid1 exit code was %d\n", status / 256);
      printf("[parent] exiting, somma is %d\n", somma);
      exit(somma);
    }
  }
  return 0;
}
