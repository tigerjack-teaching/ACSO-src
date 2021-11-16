/**
 * Simple code to show the usage of htop with child processes and the output of
 * the getpid, getppid functions.
 * You can skip this if you already did simple2
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t pidfork, pidget;

  pidfork = fork();

  if (pidfork == 0) { // figlio
    sleep(15);
    pidget = getpid();
    printf("Child with pid: %d\n", pidget);
  }
  else {
    sleep(15);
    pidget = getpid();
    printf("Parent with pid: %d, my child has pid %d\n", pidget, pidfork);
  }
  
  return 0;
}
