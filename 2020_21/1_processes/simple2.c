/**
 * Simple code to show the usage of htop with child processes and the output of
 * the getpid, getppid functions

 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid1, pid2;
  int ws1, ws2;

  printf("P> Before fork, my PID is %d\n", getpid());
  printf("P> Before fork, my PPID is %d\n", getppid());
  pid1 = fork();
  if (pid1 == 0) { // child 1
    printf("C1> PID: %d, PPID: %d\n", getpid(), getppid());
    sleep(50);
    exit(1);
  } else { // parent
    printf("P> after fork1, 1st child PID: %d\n", pid1);
    pid2 = fork();
    if (pid2 == 0) { // child 2
      printf("C2> PID: %d, PPID: %d\n", getpid(), getppid());
      sleep(45);
      exit(2);
    } else { // parent
      printf("P> after fork2, 2nd child PID: %d\n", pid2);
      int rs1 = wait(&ws1);
      printf("P> Child %d terminated with status %d\n", rs1, ws1 / 256);
      int rs2 = wait(&ws2);
      printf("P> Child %d terminated with status %d\n", rs2, ws2 / 256);
    }
  }
  return 0;
}
