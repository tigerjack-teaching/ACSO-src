#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

void *tf(void *args) {
  // To comply to POSIX standard, getpid returns PPID, gettid returns PID
  printf("pid is %u, tid is %lu\n", getpid(), syscall(SYS_gettid));
  // From htop, observe the PID and PPID values while the threads are sleeping.
  // Suggestion: use ctrl-S to freeze the output of the shell (and hence of
  // htop), ctrl-Q to resume it.
  sleep(5);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t pts[3];
  for (int i = 0; i < 3; i++) {
    pthread_create(&pts[i], NULL, &tf, NULL);
  }
  for (int i = 2; i >= 0; i--) {
    pthread_join(pts[i], NULL);
  }

  return 0;
}
